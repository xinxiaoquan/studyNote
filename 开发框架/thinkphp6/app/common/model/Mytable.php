<?php
namespace app\common\model;
use \think\Model;

class Mytable extends Model {
	public function getDataById($id, $limit=10) {
			if (!$id || (int)$id === 0)
					return [];
			$res=$this
					->table("mytable")
					->where("id=".$id)
					->limit($limit)
					->select()
					->toArray();
			return $res;
	}
}
