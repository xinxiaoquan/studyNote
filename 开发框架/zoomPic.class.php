<?php
include "GD.class.php";

class zoomPic {
	private $picPath;
	private $picName;
	private $imgW;
	private $imgH;
	private $boardW;
	private $boardH;
	public function __construct($picPath) {
		$this->picPath = $picPath;
		$this->picName = basename($picPath);
		$range = 800;
		$picInfo = getimagesize($picPath);
		$this->imgW = $picInfo[0];
		$this->imgH = $picInfo[1];
		$multiple = 1;
		if ($this->imgW/$range >= $this->imgH/$range)
			$multiple = ceil($this->imgW/$range);
		else $multiple = ceil($this->imgH/$range);
		$this->boardW = round($this->imgW/$multiple);
		$this->boardH = round($this->imgH/$multiple);
	}
	public function replace() {
		$board = new Draw($this->boardW, $this->boardH);
		$board->thumb($this->picPath,0,0,0,0,$this->boardW,$this->boardH);
		$board->print($this->picPath);
	}
}




































