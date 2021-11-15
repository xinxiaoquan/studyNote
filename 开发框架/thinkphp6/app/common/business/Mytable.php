<?php
namespace app\common\business;

class Mytable {
	protected $mytable;
	public function __construct() {
		$this->mytable=new \app\common\model\Mytable;
	}
	public function getDataById($id, $limit=10) {
		$res=$this->mytable->getDataById($id, $limit);
		if (count($res)==0) return [];
		//$sexConfig=config("sex");
		$sexConfig=[
			"女","男"
		];
		foreach ($res as $k=>$v) {
			if(!isset($v["sex"])) continue;
			$res[$k]["sex"]=$sexConfig[$v["sex"]];
		}
		return $res;
	}
}


























