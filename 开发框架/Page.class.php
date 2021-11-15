<?php
class Page {
    private $all_data_count; //所有数据条数
    private $one_page_count; //每页显示数据条数
    private $now_page_num; //当前第几页
    private $all_page_count; //一共多少页
		private $keyword;//查询的关键字

    public function __construct($all_data_count, $one_page_count, $now_page_num, $keyword="") {
        $this->all_data_count = (int)$all_data_count;
        $this->one_page_count = (int)$one_page_count;
        $this->now_page_num = (int)$now_page_num;
        //计算一共多少页
        $this->all_page_count = ceil(
            $this->all_data_count / $this->one_page_count
        );
				if ($keyword)
					$this->keyword = "&keyword=".$keyword;
    }

    //创建分页导航条的方法
    public function create() {
        //固定首页按钮
        $page = "<ul>";
        if ($this->now_page_num == 1)
            $page .= "<li><a href='?page=1{$this->keyword}' class='active'>首页</a></li>";
        else $page .= "<li><a href='?page=1{$this->keyword}'>首页</a></li>";

        //遍历中间的导航按钮
        $start = $this->now_page_num - 3;
        if ($start <= 2) $start = 2;
        $end = $this->now_page_num + 3;
        if ($end >= $this->all_page_count)
            $end = $this->all_page_count - 1;
        for ($i = $start; $i <= $end; $i++) {
            if ($this->now_page_num == $i)
                $page .= "<li><a href='?page={$i}{$this->keyword}' class='active'>{$i}</a></li>";
            else $page .= "<li><a href='?page={$i}{$this->keyword}'>{$i}</a></li>";
        }

        //固定尾页按钮
        if ($this->now_page_num == $this->all_page_count)
            $page .= "<li><a href='?page={$this->all_page_count}{$this->keyword}' class='active'>尾页</a></li>";
        else $page .= "<li><a href='?page={$this->all_page_count}{$this->keyword}'>尾页</a></li>";

				$page .= "<li>(共{$this->all_page_count}页)</li>";

        return $page;
    }
}































