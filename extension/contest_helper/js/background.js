chrome.contextMenus.create({
    'type':'normal',
    'title':'copy input data to ClipBoard',
    'contexts':['selection'],
    'id':'codecopy',
    'onclick':copydata
});

function translate(info, tab){
    var url = 'http://translate.google.com.hk/#auto/zh-CN/'+info.selectionText ;
    window.open(url, '_blank');
}

function copydata(info, tab){
    var data = info.selectionText;
    // alert(data);//this is available options to show data.
    var transfer = document.getElementById('CopyTransfer');
        if (!transfer) {
            transfer = document.createElement('textarea');
            transfer.id = 'CopyTransfer';
            transfer.style.position = 'absolute';
            transfer.style.left = '-9999px';
            transfer.style.top = '-9999px';
            document.body.appendChild(transfer);
        }
        transfer.value = data;
        transfer.focus();
        transfer.select();
        var is_copy = document.execCommand('Copy', false, null);
        alert(is_copy);

        // chrome.tabs.getCurrent(function(tab){
        //   // console.log(tab);
        //   alert(tab);
        // });
        // var notification = webkitNotifications.createNotification('images/icon48.png',
        //     'Notification Demo',
        //     'Merry Christmas');
        //
        // notification.show();
        // setTimeout(function(){notification.cancel();},5000);
}

chrome.runtime.onMessage.addListener(function(message, sender, sendResponse){
    // chrome.contextMenus.update('cn',{
    //     'title':'使用Google翻译“'+message+'”'
    // });
});
