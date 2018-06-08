window.onmouseup = function(){
    var selection = window.getSelection();
    if(selection.anchorOffset != selection.extentOffset){
        chrome.runtime.sendMessage(selection.toString());
    }
}

function getSampleInput(){
  var inputdata = getElementsByClassName("sample-test");
  alert(inputdata);
}

window.onload = function(){
  var inputdata = getElementsByClassName("sample-test");
  alert(inputdata);
}
