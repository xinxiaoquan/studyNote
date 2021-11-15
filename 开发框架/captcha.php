<?php
require_once "GD.class.php";
//封装验证码类
class Captcha {

		//验证码的宽度
		private $width;
		//验证码的高度
		private $height;
		//验证码字符的个数
		private $num;
		//验证码字体文件
		private $font_family;
		//验证码字体大小
		private $font_size;
		//生成干扰线条数
		private $lines;
		//生成干扰像素点个数
		private $pixel;

		public function __construct($width, $height, $num, $font_family, $font_size, $lines, $pixel) {
				$this->width = $width;
				$this->height = $height;
				$this->num = $num;
				$this->font_family = realpath($font_family);
				$this->font_size = $font_size;
				$this->lines = $lines;
				$this->pixel = $pixel;
		}

		//生成验证码
		public function get() {
			 $image = new Draw($this->width, $this->height);
			 $image->set_color(
					 $this->getRGB(100, 200),
					 $this->getRGB(100, 200),
					 $this->getRGB(100, 200)
			 );
			 $image->fill(0, 0);
			 $str = "";
			 for ($i = 0; $i < $this->num; $i ++) {
					 $image->set_color(
							 $this->getRGB(0, 99),
							 $this->getRGB(0, 99),
							 $this->getRGB(0, 99)
					 );
					 $char = $this->getLetter();
					 $str .= $char;
					 $image->text(
							 $this->font_size,
							 mt_rand(-30, 30),
							 ($this->width/$this->num)*$i+5,
							 27,
							 $this->font_family,
							 $char
					 );
			 }
			 for ($i = 0; $i < $this->lines; $i++) {
					 $image->set_color(
							 $this->getRGB(100, 200),
							 $this->getRGB(100, 200),
							 $this->getRGB(100, 200)
					 );
					 $image->line(
							 mt_rand(0, $this->width),
							 mt_rand(0, $this->height),
							 mt_rand(0, $this->width),
							 mt_rand(0, $this->height)
					 );
			 }
			 for ($i = 0; $i < $this->pixel; $i++) {
						$image->set_color(
								$this->getRGB(0, 100),
								$this->getRGB(0, 100),
								$this->getRGB(0, 100)
						);
						$image->pixel(
								mt_rand(0, $this->width),
								mt_rand(0, $this->height)
						);
				}
			 $image->print();
			 return $str;
		}

		//获取RGB颜色
		private function getRGB($min, $max) {
				return mt_rand($min, $max);
		}

		//随机生成字母和数字
		private function getLetter() {
				do {
						$num = mt_rand(65, 122);
				} while ($num < 97 && $num > 90);
				if (mt_rand(1, 10) >= 5)
						return mt_rand(0, 9);
				return chr($num);
		}
}

$captcha = new Captcha(100, 40, 4, "123.ttf", 20, 15, 20);

session_start();
$_SESSION["captcha"] = $captcha->get();


























