function TBGuoHuaKuai() {
		var iframe = document.querySelector("iframe");
		if (!iframe) return false;
		var doc = iframe.contentDocument;
		if (!doc) return false;
		var huakuai = doc.querySelector("#nc_1_n1z");
		if (!huakuai) return false;
		var event = document.createEvent('MouseEvents');
		event.initEvent('mousedown', true, false);
		huakuai.dispatchEvent(event);
		event = document.createEvent('MouseEvents');
		event.initEvent('mousemove', true, false);
		Object.defineProperty(event, 'clientX', {get() { return 260; } })
		huakuai.dispatchEvent(event);
		return true;
}