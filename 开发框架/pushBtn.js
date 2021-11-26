function pushBtn(name, clickEvent) {
	let btn=document.createElement("button");
	$(btn).html(name)
	.click(clickEvent)
	.css({
		position:"fixed",
		top:"50px",
		right:"-80px",
		padding:"10px",
		"z-index":9999,
		"background":"#fff",
		"border":"1px solid #333"
	})
	.mouseenter(function() {
		$(this).stop().animate({
			right:0
		});
	})
	.mouseleave(function() {
		$(this).stop().animate({
			right:"-80px"
		});
	});
	document.body.appendChild(btn);
	return btn;
}