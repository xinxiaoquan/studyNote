<?php
namespace app\site\controller;
use app\BaseController;
use app\common\business\Mytable;

class Index extends BaseController
{
    public function index()
    {
        /* $mytable=new Mytable();
				$id=request()->param("id");
				$res=$mytable->getDataById($id, 1);
				return json($res);  */
				return $arr;
    }

    public function hello($name = 'ThinkPHP6')
    {
        return 'hello,' . $name;
    }
}















