function setInputValue(node, text) {
    var nodeName = node.nodeName.toLowerCase();
    var event;
    var descriptor;
    if (nodeName === 'input' || nodeName === 'textarea') {
        //获取getter setter
        descriptor = Object.getOwnPropertyDescriptor(node, 'value');
        //删除value的getter和setter并重新赋值
        delete node['value'];
        node.value = text;
        //触发事件以便react和vue内部更改值
        event = document.createEvent('HTMLEvents');
        event.initEvent('propertychange', false, false);
        event.propertyName = 'value';
        node.dispatchEvent(event);
        //必须同时触发，缺一不可
        event = document.createEvent('HTMLEvents');
        event.initEvent('input', true, false);
        node.dispatchEvent(event);
        //重新绑定getter和setter
        if (descriptor) {
            Object.defineProperty(node, 'value', descriptor);
        }
    }
}