<?php
class Session {
	//session id
	private $sessionId;
	//cookie中的session标识
	private $cookieName="QUANSESSION";
	//cookie的有效期（默认浏览器关闭清除）
	private $cookieTime=null;
	//session数据的数组
	private $SESSION = [];
	//session数据的过期时间
	private $lifeTime=1500;
	//存储文件还是数据库
	private $saveMode="file";
	//默认存储文件的路径
	private $savePath="c:/temp/";
	//数据库连接对象(new mySQLi)
	private $databaseLink = null;
	
	//初始化session类
	public function __construct($saveMode=false, $savePath=false, $databaseInfo=false, $lifeTime=false, $cookieName=false, $cookieTime=false) {
		//生成随机字符串(session id)
		function getStr() {
			$str = "";
			for ($i = 0; $i < 22; $i++) {
				if (mt_rand(1, 10) >= 5) {
					$str .= mt_rand(0, 9);
					continue;
				}
				do {
						$num = mt_rand(65, 122);
				} while ($num < 97 && $num > 90);
				$str .= chr($num);
			}
			return $str.".session";
		}
		
		if ($saveMode)
			$this->saveMode = $saveMode;
		if ($savePath)
			$this->savePath = $savePath;
		if ($lifeTime)
			$this->lifeTime = $lifeTime;
		
		//设置cookie的信息
		if ($cookieName)
			$this->cookieName = $cookieName;
		if ($cookieTime)
			$this->cookieTime = time()+$cookieTime;
		
		//session id不存在就创建一个
		$sessionId = @$_COOKIE[$this->cookieName];
		if (!$sessionId)
			$sessionId = getStr();
		$this->sessionId = $sessionId;
		
		
		//如果以数据库形式存储session
		if ($saveMode && $saveMode == "database") {
			$this->startDatabase($databaseInfo);
			$res = $this->databaseLink->query("SELECT * FROM session WHERE s_id='{$sessionId}'");
			$row = $res->fetch_assoc();
			if (!$row) {
				$this->databaseLink->query("INSERT INTO session VALUES('{$sessionId}', '[]', ".time().")");
				$this->SESSION = [];
				setcookie($this->cookieName, $this->sessionId, $this->cookieTime);
			} else $this->SESSION = (array)json_decode($row["s_content"]);
		//如果以文件方式存储session
		} else {
			$this->startSavePath($savePath);
			if (!file_exists($this->savePath.$sessionId)) {
				file_put_contents($this->savePath.$sessionId, "[]");
				$this->SESSION = [];
				setcookie($this->cookieName, $this->sessionId, $this->cookieTime);
			} else $this->SESSION = (array)json_decode(file_get_contents($this->savePath.$sessionId));
		}
	}
	
	//操作session数据的数组
	public function get($key) {
		return $this->SESSION[$key];
	}
	public function getAll() {
		return $this->SESSION;
	}
	public function set($key, $value) {
		$this->SESSION[$key] = $value;
		
		$data = json_encode($this->SESSION, JSON_UNESCAPED_UNICODE);
		if ($this->saveMode == "file")
			$this->writeToFile($data);
		if ($this->saveMode == "database")
			$this->writeToDatabase($data);
	}
	public function clear() {
		$this->SESSION = [];
		
		if ($this->saveMode == "file")
			$this->writeToFile("[]");
		if ($this->saveMode == "database")
			$this->writeToDatabase("[]");
	}
		
	//初始化存储session的数据库
	private function startDatabase($info) {
		if (!$info) return;
		
		//连接数据库
		$this->databaseLink = new mySQLi(
			$info["host"],
			$info["user"],
			$info["pwd"],
			$info["database"],
			$info["port"]
		);
		
		//判断表存不存在，不存在就创建一个规范的表
		$res = $this->databaseLink->query("SHOW TABLES LIKE 'session'");
		if (!$res->fetch_assoc()) {
			$sql = "CREATE TABLE session(s_id varchar(32) primary key, s_content text, put_time int unsigned)";
			$this->databaseLink->query($sql);
		}
		
		$sql = "UPDATE session SET put_time=".time()." WHERE s_id='{$this->sessionId}'";
		$this->databaseLink->query($sql);
		
		//清除过期session数据记录
		$now = time();
		$time = $now - $this->lifeTime;
		$sql = "DELETE FROM session WHERE put_time<{$time}";
		$this->databaseLink->query($sql);
	}
	//初始化存储session的文件
	private function startSavePath($savePath) {
		if ($savePath) $this->savePath = $savePath;
		
		//如果目录不存在就创建一个
		if (!is_dir($this->savePath))
			mkdir($this->savePath, "0777", true);
	
		if (file_exists($this->savePath.$this->sessionId))
			touch($this->savePath.$this->sessionId);
		
		//过期文件的清除
		$now = time();
		$dir = opendir($this->savePath);
		while ($fileName = readdir($dir)) {
			if ($fileName != "." && $fileName != ".." && strpos($fileName, ".session") !== false) {
				$fileName = $this->savePath.$fileName;
				$createTime = filemtime($fileName);
				if ($createTime + $this->lifeTime < $now)
					unlink($fileName);
			}
		}
	}
	
	//把session数据写入数据库或文件
	private function writeToDatabase($data) {
		$sql = "SELECT * FROM session WHERE s_id='{$this->sessionId}'";
		$res = $this->databaseLink->query($sql);
		if (!$res->fetch_assoc()) return;
		$sql = "UPDATE session SET s_content='{$data}' WHERE s_id='{$this->sessionId}'";
		$this->databaseLink->query($sql);
	}
	private function writeToFile($data) {
		if (!file_exists($this->savePath.$this->sessionId))
			return;
		file_put_contents($this->savePath.$this->sessionId, $data);
	}
}


/* $session = new Session("database", null, [
	"host"=>"127.0.0.1",
	"user"=>"root",
	"pwd"=>"root",
	"database"=>"xinxiaoquan",
	"port"=>3306
], 5);
//$session->set("aaa", "bbb");
var_dump($session->getAll());
 */

$session = new Session(false, false, false, 5);
/* $session->set("我的姓名", "耿康康");
$session->set("我的QQ", "3111381465"); */
var_dump($session->getAll());









