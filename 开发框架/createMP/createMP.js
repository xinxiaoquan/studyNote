/*
	配置的对象信息
		setTitle 设置网页标题
		setWidth 设置元素默认宽度
		setBGC 设置背景颜色
		setBGImg 设置背景图片
		filePath 文件地址
		width 自定义宽度（带单位）
		targetTo 跳转到编号(元素的编号)
			子元素选择器（是自己写self） 跳转编号
		addHtml 嵌入添加html代码
			x x轴坐标
			y y轴坐标
			inner 代码内容
			auto 是否自动随着父元素位置和宽度变化（默认是）
			数组传入，可添加多个
		addEvents 添加事件
			子元素选择器（是自己写self）
				事件名 方法
		setCSs 设置css
			子元素选择器（是自己写self）
				字符串传入css样式表
		addPic 添加视频封面图片地址（视频元素独有）
		TBTitle 商品（店铺）标题
		TBUrl 商品（店铺）链接
		tableData 表格数据（表格元素独有）
			传入一个二维数组（数组的每个元素都是一行）
		tableHeadStress 表格表头强调（表格元素独有）
			布尔值
		comments 评论数据（评论元素独有）
			nickname 昵称
			content 评论内容
			pics 评论图片（数组）
			reply 回复内容
			数组传入，可添加多个
		inner 添加内容（添加HTML元素可用）

	对象的方法：
		pushImg([
			filePath
		]) 添加图片
		pushImgs([1.jpg,2.jpg]) 批量添加图片 
			传入数组，设置文件路径就行
		pushVideo() 添加视频
		pushNav() 添加导航条 
		pushTBCard() 添加淘宝商品卡片
		pushBlock 添加一个段落
		pushTable 添加一个表格
		pushComments 添加一些评论
		pushHeadPics 添加一些头像图片，直接传入数组
		pushHtml 添加自定义html代码
		setAttrByNum() 为某个元素（序号）设置属性
		clone() 克隆一个元素（传入元素序号）
		debugger() 调试模式（显示每个元素的序号）

*/
function createMP() {
	if (this == window) return;
	(function() {
		var SP = document.querySelector("script[src$='createMP.js']");
		if (!SP) return;
		var path = SP.getAttribute("src");
		path = path.replace("createMP.js", "createMP.css");
		var MPCSS = "<link rel='stylesheet' type='text/css' href='"+path+"' />";
		document.head.innerHTML += MPCSS;
		var viewport = `<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no">`;
		document.head.innerHTML += viewport;
		if (document.head.innerHTML.indexOf("charset=") == -1)
			document.head.innerHTML += "<meta charset='utf-8'>";
	})();
	
	var that = this;
	var headImgs = [];
	this.fragment = document.createDocumentFragment();
	this.maxWidth = "800px";
	this.minWidth = "300px";
	this.isDebugger = false;
	this.setTitle = function(title) {
		document.title = title;
	}
	this.setWidth = function(width) {
		this.maxWidth = width;
	}
	this.setBGC = function(color) {
		document.body.style.backgroundColor = color;
	}
	this.setBGImg = function(img) {
		document.body.style.backgroundImage = "url("+img+")";
	}
	this.pushImg = function(config) {
		if(!isObj(config)) return;
		var div = document.createElement("div");
		div.className = "img";
		var img = document.createElement("img");
		div.appendChild(img);
		setAttrMain(config, div, img);
		this.fragment.appendChild(div);
	}
	this.pushVideo = function(config) {
		if(!isObj(config)) return;
		var div = document.createElement("div");
		div.className = "video";
		var video = document.createElement("video");
		video.controls = true;
		div.appendChild(video);
		setAttrMain(config, div, video);
		this.fragment.appendChild(div);
	}
	this.pushImgs = function(imgs) {
		for (var i = 0; i < imgs.length; i++)
			this.pushImg({
				filePath:imgs[i]
			});
	}
	this.pushTBCard = function(config) {
		if(!isObj(config)) return;
		var div = document.createElement("div");
		div.className = "TBCard";
		var a = document.createElement("a");
		setAttrMain(config, div, a);
		div.appendChild(a);
		this.fragment.appendChild(div); 
	}
	this.pushBlock = function(config) {
		if(!isObj(config)) return;
		var box = document.createElement("div");
		box.className = "block";
		setAttrMain(config, box);
		this.fragment.appendChild(box);
	}
	this.pushTable = function(config) {
		if(!isObj(config)) return;
		var table = document.createElement("div");
		table.className = "table";
		setAttrMain(config, table);
		this.fragment.appendChild(table);
	}
	this.pushHeadPics = function(pathArr) {
		for (var i = 0; i < pathArr.length; i++)
			headImgs.push(pathArr[i]);
	}
	this.pushComments = function(config) {
		if(!isObj(config)) return;
		var com = document.createElement("div");
		com.className = "comment";
		setAttrMain(config, com);
		this.fragment.appendChild(com);
	}
	this.pushHtml = function(config) {
		if(!isObj(config)) return;
		var html = document.createElement("div");
		html.className = "html";
		setAttrMain(config, html);
		this.fragment.appendChild(html);
	}
	this.pushNav = function(config) {
		if(!isObj(config)) return;
	}
	this.clone = function(num) {
		if (!num) num = 1;
		var sub = Number(num-1);
		var child = this.fragment.children[sub];
		if (!child) return;
		var elem = child.cloneNode(true);
		this.fragment.appendChild(elem);
	}
	this.setAttrByNum = function(num, config) {
		if(!isObj(config)) return;
		var sub = Number(num-1);
		setAttrMain(config, this.fragment.children[sub]);
	}
	this.debugger = function() {
		this.isDebugger = true;
	}
	this.print = function() {
		var length = this.fragment.children.length;
		for (var i = 0; i < length; i++) {
			if (this.isDebugger) {
				var numElem = document.createElement("div");
				numElem.className = "debugger";
				numElem.innerHTML = i+1;
				this.fragment.children[i].appendChild(numElem);
			}
			this.fragment.children[i].className += " target"+(i+1);
		}
		document.body.appendChild(this.fragment);
	}
	
	function isObj(obj) {
		if (obj instanceof Object)
			return true;
		return false;
	}
	function setAttrMain(config, parent, child) {
		var parentW = that.maxWidth;
		parent.style.maxWidth = that.maxWidth;
		parent.style.minWidth = that.minWidth;
		parent.className += " layout";
		if (config.hasOwnProperty("filePath") && child)
			child.src = config["filePath"];
		if (config.hasOwnProperty("addPic") && child)
			child.poster = config["addPic"];
		if (config.hasOwnProperty("width")) {
			parent.style.maxWidth = config["width"];
			parentW = config["width"];
		}
		if (config.hasOwnProperty("TBTitle")) 
			setTBTitle(child, config["TBTitle"]);
		if (config.hasOwnProperty("TBUrl"))
			setTBUrl(child, config["TBUrl"]);
		if (config.hasOwnProperty("addHtml")) {
			for (var i = 0; i < config["addHtml"].length; i++) {
				var html = createBoxHtml(config["addHtml"][i], parentW);
				parent.appendChild(html);
			}
		}
		if (config.hasOwnProperty("targetTo")) setTargetTo(parent, config["targetTo"]);
		if (config.hasOwnProperty("addEvents")) addEevents(parent, config["addEvents"]);
		if (config.hasOwnProperty("setCss")) setCss(parent, config["setCss"]);
		if (config.hasOwnProperty("inner")) parent.innerHTML = config["inner"];
		if (config.hasOwnProperty("tableData")) {
			var data = config["tableData"];
			for (var i = 0; i < data.length; i++) {
				var ul = document.createElement("ul");
				for (var j = 0; j < data[i].length; j++) {
					var li = document.createElement("li");
					li.innerHTML = data[i][j];
					li.style.width = (1/data[i].length*100)+"%";
					ul.appendChild(li);
				}
				parent.appendChild(ul);
			}
		}
		if (config.hasOwnProperty("tableHeadStress") && config["tableHeadStress"]) {
			parent.firstChild.style.fontWeight = "bold";
		}
		if (config.hasOwnProperty("comments")) {
			var data = config["comments"];
			for (var i = 0; i < data.length; i++) {
				var nickname = data[i]['nickname'];
				var content = data[i]['content'];
				var pics = data[i]['pics'];
				var reply = data[i]['reply'];
				
				nickname = nickname?nickname:"匿名";
				content = content?content:"";
				pics = pics?pics:[];
				reply = reply?reply:"感谢您的购买，祝您生活愉快！";
				
				var partElem = document.createElement("div");
				partElem.className = "part";
				var hIElem  = document.createElement("div");
				hIElem.className = "headImg";
				hIElem.style.backgroundImage = `url(${headImgs[i]})`;
				var nElem = document.createElement("div");
				nElem.className = "nickname";
				nElem.innerHTML = nickname;
				var cElem = document.createElement("div");
				cElem.className = "content";
				cElem.innerHTML = content;
				var pElems = document.createDocumentFragment();
				for (var j = 0; j < pics.length; j++) {
					var a = document.createElement("a");
					a.target = "_blank";
					var pElem = document.createElement("img");
					pElem.src = pics[j];
					a.href = pics[j];
					a.appendChild(pElem);
					pElems.appendChild(a);
				}
				var rElem = document.createElement("div");
				rElem.className = "reply";
				rElem.innerHTML = reply;
				
				partElem.appendChild(hIElem);
				partElem.appendChild(nElem);
				partElem.appendChild(cElem);
				partElem.appendChild(pElems);
				partElem.appendChild(rElem);
				
				parent.append(partElem);
			}
		}
	}
	function setTargetTo(elem, info) {
		if (!elem) return;
		for (var key in info) {
			var targetId = info[key];
			var origin = [elem];
			if (key != "self")
				origin = elem.querySelectorAll(key);
			if (origin.length == 0) continue;
			for (var i = 0; i < origin.length; i++) {
				origin[i].className += " pointer";
				(function(targetId, origin) {
					origin.addEventListener("click", function(e) {
						if (e.target != this) return;
						if (isNaN(Number(targetId))) {
							open(targetId);
							return;
						}
						var target = document.querySelector(".target"+targetId);
						if (target) target.scrollIntoView();
					});
				})(targetId, origin[i]);
			}
		}
	}
	function createBoxHtml(info, maxWidth) {
		var x = info["x"];
		var y = info["y"];
		var inner = info["inner"];
		var auto = info["auto"];
		if (auto === undefined)
			auto = true;
		var css = info["setCss"];
		var box = document.createElement("div");
		box.className = "box";
		box.innerHTML = inner;
		if (maxWidth.indexOf("%") != -1) {
			var num = maxWidth.replace("%", "");
			num /= 100;
			maxWidth = window.screen.width*num;
		} else maxWidth = maxWidth.replace("px", "");
		if (auto) {
			box.style.transformOrigin = "0 0";
			let timer = setInterval(function() {
				var parent = box.parentElement;
				if (parent.offsetWidth) {
					var parentW = parent.offsetWidth;
					var ratio = parentW/maxWidth;
					box.style.transform = "scale("+ratio+")";
					if (!box.getAttribute("autoXY")) {
						var parentH = parent.offsetHeight;
						var WH = parentW/parentH;
						var maxHeight = Math.round(maxWidth/WH);
						if (x.indexOf("%") == -1) {
							x = x.replace("px", "");
							box.style.left = (x/maxWidth)*100+"%";
						}
						if (y.indexOf("%") == -1) {
							y = y.replace("px", "");
							box.style.top = (y/maxHeight)*100+"%";
						}
						box.setAttribute("autoXY", true);
					}
				}
			},1500);
		}
		if (css) setCss(box, {
			self:css
		});
		box.style.left = x;
		box.style.top = y;
		return box;
	}
	function addEevents(elem, info) {
		for (var key in info) {
			var events = info[key];
			var targets = [elem];
			if (key != "self")
				targets = elem.querySelectorAll(key);
			if (targets.length == 0) continue;
			for (var i = 0; i < targets.length; i++)
				for (var name in events) {
					(function(eName, event, sub) {
						targets[sub].addEventListener(eName, function() {
							event(this);
						});
					})(name, events[name], i);
				}
		}
	}
	function setCss(elem, info) {
		for (var key in info) {
			var targets = [elem];
			if (key != "self") 
				targets = elem.querySelectorAll(key);
			if (targets.length == 0) continue;
			var css = info[key];
			css = css.replace(/\s/g, "");
			var arr = css.split(";");
			for (var i = 0; i < arr.length; i++) {
				if (!arr[i]) continue;
				var tmp = arr[i].split(":");
				for (var j = 0; j < targets.length; j++)
					targets[j].style[tmp[0]] = tmp[1];
			}
		}
	}
	function setTBTitle(elem, title) {
		elem.title = title;
		elem.innerHTML = "<span class='title'>"+title+"</span>";
	}
	function setTBUrl(elem, url) {
		elem.setAttribute("target", "_blank");
		elem.setAttribute("href", url);
	}
}