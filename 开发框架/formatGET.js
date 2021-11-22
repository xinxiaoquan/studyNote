function formatGET() {
    this.getArr = function(str) {
        if (!str) str = location.search.replace("?", "");
        let res = {};
        let tmp1 = str.split("&");
        for (let i = 0; i < tmp1.length; i++) {
            let tmp2 = tmp1[i].split("=");
            res[tmp2[0]] = tmp2[1];
        }
        return res;
    }
    this.toQuery = function(obj) {
        let res = "";
        for (let key in obj)
            res += `${key}=${obj[key]}&`;
        return res.substr(0, res.length - 1);
    }
    this.getHost = function() {
        return location.href.slice(0, location.href.indexOf("?"));
    }
}