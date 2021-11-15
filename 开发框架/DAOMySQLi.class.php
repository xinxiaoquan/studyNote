<?php
final class DAOMySQLi {
//各种数据库连接需要的数据
private $_host;
private $_user;
private $_pwd;
private $_dbname;

//本类的一个对象实例，因为是单例模式，所以只允许创建一次
private static $_DAOOBJ;

//mysql的连接对象
private $_mysqlObj;

//判断mysql连接对象是否存在
private function hasMysqlObj() {
  if ($this->_mysqlObj) return true;
  else {
    echo '错误，数据库未连接！<br/>';
    return false;
  }
}

//定义构造对象的方法
public static function getObj(array $option) {
  //判断有没有创建本类对象
  if (self::$_DAOOBJ && self::$_DAOOBJ instanceof self)
    return false;
  else {
    if (!isset($option['host']) ||
        !isset($option['user']) ||
        !isset($option['pwd']) ||
        !isset($option['dbname'])) {
      echo '<b style="color:red">错误！数据格式有误！</b><br/>';
      return false;
    }
    return self::$_DAOOBJ = new self($option);
  }
}

//定义构造方法，不允许外部访问
//参数限制为数组
private function __construct(array $option) {
  //写入数据库相关数据和验证
  $this->_host = @$option['host'];
  $this->_user = @$option['user'];
  $this->_pwd = @$option['pwd'];
  $this->_dbname = @$option['dbname'];
  
  //初始化mysql连接对象
  $link = new MySQLi(
    $this->_host,
    $this->_user,
    $this->_pwd,
    $this->_dbname,
    3306
  );
  $link -> set_charset("utf8");
  if ($link->connect_errno !== 0) {
    echo '警告，数据库连接错误，如果进行数据库操作会失败！<br/>';
    echo '错误信息：' . $link->connect_error . '<br/>';
    return;
  }
  $this -> _mysqlObj = $link;
}

//防止克隆
private function __clone() {}

//mysql获取查询语句返回的数组
public function fetch_all(string $sql) {
  if (!$this->hasMysqlObj()) return;
  
  if (!$this->isSelect($sql)) return null;
  
  $res = $this->_mysqlObj->query($sql);
  if (!$res) {
   return null;
  } else {
   if (is_bool($res)) return null;
   $resArray = [];
   while($row = $res->fetch_assoc())
    $resArray[] = $row;
   return $resArray;
 }
 $res->free();
}

//mysql增删改
public function query(string $sql) {
  if (!$this->hasMysqlObj()) return;
  
  if ($this->isSelect($sql))
    return $this->fetch_all($sql);
  
  $res = $this->_mysqlObj->query($sql);
  if ($res) return ['status'=>'ok', 'affected_rows'=>$this->_mysqlObj->affected_rows, 'insert_id'=>$this->_mysqlObj->insert_id];
  else return ['status'=>'error', 'errno'=>$this->_mysqlObj->errno, 'error'=>$this->_mysqlObj->error];
}

//判断是不是查询语句
private function isSelect(string $sql) {
  
  preg_match('/show|select|desc/i', $sql, $tmp);
  if (count($tmp)) return true;
  else false;
}

}

/* $dao = DAOMySQLi::getObj([
  'host'=>'localhost',
  'user'=>'root',
  'pwd'=>'root1234',
  'dbname'=>'testdb'
]);

echo '<pre>'; */













