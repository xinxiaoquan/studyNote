<?php
class Draw {
    private $board;
    private $color;
		private $create_fn = [
			"image/png" => "imagecreatefrompng",
			"image/gif" => "imagecreatefromgif",
			"image/jpeg" => "imagecreatefromjpeg"
		];
		private $mime = "image/jpeg";
		private $output_fn = [
			"image/png" => "imagepng",
			"image/gif" => "imagegif",
			"image/jpeg" => "imagejpeg"
		];
		
    public function __construct($width, $height) {
        $this->board = imagecreatetruecolor($width, $height);
        $this->set_color(255, 255, 255);
    }
    //设置颜色
    public function set_color($r, $g, $b) {
        if (!$this->board) return;
				$this->color = imagecolorallocate($this->board, $r, $g, $b);
    }
		//设置透明颜色
		public function set_transparent() {
			$this->color = imagecolortransparent($this->board,
				imagecolorallocate($this->board, 0, 0, 0)
			);
		}
		//设置图像的mime类型
		public function set_mime($mime) {
			$this->mime = $mime;
		}
    //填充背景
    public function fill($x, $y) {
        if (!$this->board) return;
				imagefill($this->board, $x, $y, $this->color);
    }
    //画线
    public function line($x1, $y1, $x2, $y2) {
        if (!$this->board) return;
				imageline($this->board, $x1, $y1, $x2, $y2, $this->color);
    }
    //画点
    public function pixel($x, $y) {
			if (!$this->board) return;
      imagesetpixel($this->board, $x, $y, $this->color);
    }
    //画矩形
    public function rectangle($x1, $y1, $x2, $y2, $filled=false) {
				if (!$this->board) return;
        if ($filled)
            imagefilledrectangle($this->board, $x1, $y1, $x2, $y2, $this->color);
        else imagerectangle($this->board, $x1, $y1, $x2, $y2, $this->color);
    }
    //画圆形
    public function ellipse($x, $y, $w, $h, $filled=false) {
				if (!$this->board) return;
        if ($filled)
            imagefilledellipse($this->board, $x, $y, $w, $h, $this->color);
        else imageellipse($this->board, $x, $y, $w, $h, $this->color);
    }
    //画弧形
    public function arc($c1, $c2, $w, $h, $s, $e, $filled=false) {
				if (!$this->board) return;
        if ($filled)
            imagefilledarc($this->board, $c1, $c2, $w, $h, $s, $e, $this->color, IMG_ARC_PIE);
        else imagearc($this->board, $c1, $c2, $w, $h, $s, $e, $this->color);
    }
    //拷贝图片到画布
    public function copy($src_path, $dst_x, $dst_y, $src_x, $src_y, $src_w=null, $src_h=null) {
				if (!$this->board) return;
        $img_info = getimagesize($src_path);
				$mime = $img_info["mime"];
				if (!$this->create_fn[$mime]) return;
				$src_img = $this->create_fn[$mime]($src_path);
        if ($src_w === null)
            $src_w = $img_info[0];
        if ($src_h === null)
            $src_h = $img_info[1];
        imagecopy($this->board, $src_img,  $dst_x, $dst_y, $src_x, $src_y, $src_w, $src_h);
    }
		//图像压缩
		public function thumb($src_path, $dst_x, $dst_y, $src_x, $src_y, $dst_w, $dst_h, $src_w=null, $src_h=null) {
			if (!$this->board) return;
			$img_info = getimagesize($src_path);
			$mime = $img_info["mime"];
			if (!$this->create_fn[$mime]) return;
			$src_img = $this->create_fn[$mime]($src_path);
			if ($src_w === null)
					$src_w = $img_info[0];
			if ($src_h === null)
					$src_h = $img_info[1];
			imagecopyresampled($this->board, $src_img, $dst_x, $dst_y, $src_x, $src_y, $dst_w, $dst_h, $src_w, $src_h);
		}
    //写入文字
    public function text($size, $angle, $x, $y, $font_family, $text) {
        if (!$this->board) return;
				imagettftext($this->board, $size, $angle, $x, $y, $this->color, $font_family, $text);
    }
    public function print($filename=null) {
			if ($filename) {
				$this->output_fn[$this->mime]($this->board, $filename);
        imagedestroy($this->board);
				$this->board = null;
				return;
			}
			header("content-type:{$this->mime}");
			$this->output_fn[$this->mime]($this->board);
			imagedestroy($this->board);
			$this->board = null;
    }
}




































