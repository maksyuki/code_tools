/*! Copyright 2009-2017 Evernote Corporation. All rights reserved. */

function GmailClipper(){"use strict";function a(a){return a.substr(a.search(/\d/)).split(/\d+\n/)}function b(a){return a.replace(/(,{2,})/g,function(a){return a.split("").join("null")}).replace(/(\[,|,\])/g,function(a){return a.replace("[","[null").replace("]","null]")})}function c(a){g=a;var b=document.createElement("script");b.id="evernoteGmailScript",b.innerText='var currentEmail = "";if (window.BT_WorkerInitMessage || document.defaultView.top.BT_WorkerInitMessage) {window.postMessage({name: "inboxSettings",inboxSettings: window.BT_WorkerInitMessage || document.defaultView.top.BT_WorkerInitMessage}, "*");} else {var uName = currentEmail;if (window.GLOBALS) {currentEmail = window.GLOBALS[10];uName = currentEmail;try {for (var i = 0; i < window.GLOBALS[17].length; i++) {if (window.GLOBALS[17][i] && window.GLOBALS[17][i][0] === "mla") {for (var j = 0; j < window.GLOBALS[17][i][1].length; j++) {var account = window.GLOBALS[17][i][1][j];var accountEmail = account[0];if (accountEmail.toLowerCase() === currentEmail.toLowerCase()) {uName = account[4];break;}}}}} catch (ex) {console.error(ex);}window.postMessage({name: "receiveGmailIk",baseUrl: window.GLOBALS[31],ik: window.GLOBALS[9],user: { email: currentEmail, name: uName }}, "*");} else {try {var mainTable = document.querySelectorAll(\'div.maincontent  table\');if (mainTable.length > 0) {var el = mainTable[1].querySelector(\'tr > td > font\');if (el) {if (el.childNodes.length == 2) {uName = el.childNodes[0].innerHTML;currentEmail = el.childNodes[1].textContent;currentEmail = currentEmail.substring(1, currentEmail.length - 1);}}var content = mainTable[1].querySelector(\'div [dir]\').innerHTML;}} catch (ex) {console.error(ex);}window.postMessage({name: "receiveGmailIk",baseUrl: window.location.origin + window.location.pathname,preview: true,content: content,user: { email: currentEmail, name: uName }}, "*");}}document.body.removeChild(document.getElementById("evernoteGmailScript"));',document.body.appendChild(b)}function d(c,e,f,h,i,j,k){var l=new XMLHttpRequest;l.open("POST",c),l.baseUrl=c,l.ik=e,l.threadId=f,l.numRetryMsgs=h.length,l.thread=i,l.threadingEnabled=j,l.onreadystatechange=function(){if(4==this.readyState)if(200==this.status){for(var c=a(this.response),e=[],f=0;f<c.length;f++)if(!(""==c[f].trim()||c[f].indexOf('"ms"')<0)){var h=b(c[f]);try{for(var i=JSON.parse(h),j=0;j<i.length;j++){var l=i[j];if("ms"==l[0]&&l[3]>=2&&l[3]<=4){var m=l[1],n=new GmailMessage(this.baseUrl);if(l[13]){n.setAuthorInfo(l[5],l[6]),this.thread.setSubject(l[13][21]);var o=k||l[13][6];n.setBody(o),this.thread.addParticipants([[l[5],l[6]]]),this.thread.addParticipants(l[13][9][1]),this.thread.addParticipants(l[13][9][0]),n.addAttachments(l[13][7][0]),n.setDate(l[24])}else e.push(m);this.thread.addMessage(n,m)}}}catch(a){return log.error("\n"+a.stack),log.log(h.substring(0,255)),void g(null,"Could not parse. check console for more details")}}e.length>0&&0===this.numRetryMsgs?d(this.baseUrl,this.ik,this.threadId,e,this.thread,this.threadingEnabled):e.length>0?(this.thread.removeMessages(e),g(this.thread)):g(this.thread)}else log.error("could not download gmail thread "+this.threadId+" with ik="+this.ik+" because of ("+this.status+") "+this.response),g(null,this.status)},l.setRequestHeader("Content-type","application/x-www-form-urlencoded");var m="ik="+l.ik+"&ui=2&view=cv&ser=1&th="+l.threadId+"&pcd=1&mb="+(l.threadingEnabled?"0":"1")+"&rt=c";h.length>0?m+="&msgs="+h.join(",")+"&search=inbox":m+="&search=query",l.send(m)}function e(c,d,e){var f=new XMLHttpRequest;f.open("POST",c),f.baseUrl=c,f.ik=d,f.onreadystatechange=function(){if(4==this.readyState)if(200==this.status)try{var c=a(this.response),d=!0;a:for(var f=0;f<c.length;f++)if(!(""==c[f].trim()||c[f].indexOf('"p"')<0))for(var h=JSON.parse(b(c[f])),i=0;i<h.length;i++)if("p"==h[i][0])for(var j=0;j<h[i][1].length;j++)if("bx_vmb"==h[i][1][j][0]){d=0==h[i][1][j][1];break a}e(this.baseUrl,this.ik,d)}catch(a){log.error("could not parse the settings response.\n"+a.stack),log.log(this.response),g(null,"could not parse settings. check internal clipper logs for more details")}else log.error("could not download settings from baseUrl="+this.baseUrl+", ik="+this.ik+" with status ("+this.status+") "+this.response),e(this.baseUrl,this.ik,!0)},f.setRequestHeader("Content-type","application/x-www-form-urlencoded"),f.send("ik="+d+"&view=pu&rt=c")}function f(a,b){b||(b=window.location.href),a=a.replace(/[\[\]]/g,"\\$&");var c=new RegExp("[?&]"+a+"(=([^&#]*)|&|#|$)","i"),d=c.exec(b);return d?d[2]?decodeURIComponent(d[2].replace(/\+/g," ")):"":null}var g;window.addEventListener("message",function(a){if("receiveGmailIk"==a.data.name)if(/mail\/$/.test(a.data.baseUrl)&&(a.data.baseUrl+="u/0/"),1==a.data.preview){a.data.ik=f("ik");var b=new GmailThread;b.setUser(a.data.user.name,a.data.user.email);var c=f("msg");d(a.data.baseUrl,a.data.ik,c,[],b,!1,a.data.content)}else e(a.data.baseUrl,a.data.ik,function(b,c,e){var f=null;if(/#.+?.*\/(.+?)($|\?)/.test(window.location.href))f=/#.+?.*\/(.+?)($|\?)/.exec(window.location.href)[1];else for(var h=document.querySelectorAll("[class^=m], [class*=' m']"),i=0;i<h.length;i++)if(/(\s|^)m([^\s]{5,})/.test(h[i].className)){f=/(\s|^)m([^\s]{5,})/.exec(h[i].className)[2];break}if(!f)return log.error("could not find thread Id for email: "+window.location.href),void g(null,"could not find thread id. check clipper logs for more details");var j=new GmailThread;j.setUser(a.data.user.name,a.data.user.email),d(b,c,f,[],j,e)});else if("inboxSettings"==a.data.name){var h=JSON.parse(a.data.inboxSettings),i=document.querySelector("[aria-expanded=true][aria-multiselectable=false],[aria-expanded=true][aria-multiselectable=true] .scroll-list-item-open");if(!i)return log.error("could not find thread Id for email: "+window.location.href),void g(null,"could not find thread id. check clipper logs for more details");var j=i.querySelectorAll("[data-msg-id]"),c=i.getAttribute("data-item-id");if(!j||!j.length)try{var b=new GmailThread,k=i.querySelector("label").innerText;b.setSubject(k);var l=new GmailMessage("");return l.setBody(i.querySelector('[role="combobox"]').innerText),l.setAuthorInfo(k,""),l.setDate((new Date).toLocaleString()),b.addMessage(l,0),void g(b)}catch(a){return log.error("Could not find messages in the thread"),void g(null,"could not find messages in the thread. check clipper logs for more details")}for(var m=[],n=0;n<j.length;n++){var o=j[n].getAttribute("data-msg-id");m.push(o)}var p={};p[1]={},p[1][2]=h[110][4][36376563][3],p[1][5]=h[110][4][36376563][34],p[1][10]=8,p[1][33943352]={},p[1][33943352][3]=h[110][4][36376563][1][3],p[1][33943352][5]=h[110][4][36376563][1][5],p[1][33943352][7]=h[110][4][36376563][1][7],p[1][33943352][8]=h[110][4][36376563][1][8],p[1][33943352][9]=h[110][4][36376563][1][9],p[1][33943352][10]=5,p[1][33943352][11]="",p[1][33943352][12]=108e5;for(var n=0;n<h[110][4][36376563][33][1].length;n++)if(h[110][4][36376563][33][1][n][4]){p[1][33943352][13]=h[110][4][36376563][33][1][n][4];break}p[1][33943352][14]=1,p[1][33943352][16]=h[110][4][36376563][3],p[101]={},p[101][1]=[];for(var n=0;n<m.length;n++){var q={};q[1]={},q[1][2]={1:"gmail:"+m[n].substring(m[n].indexOf("#")+1),98517530:{1:c.substring(c.indexOf("#gmail:")+"#gmail:".length),2:m[n].substring(m[n].indexOf("#")+1)}},q[1][3]="0",q[1][4]=["S","D"],q[4]=["S","D"],p[101][1].push(q)}var r=JSON.stringify(p),s=h[110][4][36376563][12]||"",t=h[110][4][36376563][25]+"/sync"+s+"/cumulus?btd=1&c=777",u=new XMLHttpRequest;u.open("POST",t),u.request=p,u.onreadystatechange=function(){if(4===this.readyState)if(200===this.status){var a=JSON.parse(this.response);if(a.length>0){for(var b=new GmailThread,c=0;c<a[0][101][1].length;c++)for(var d=0;d<a[0][101][1][c][4].length;d++){var e=a[0][101][1][c][4][d];if(e[1][2][87656922]){b.subject||b.setSubject(e[1][2][87656922][8]);var f=new GmailMessage("");f.setAuthorInfo(e[1][2][87656922][2][3],e[1][2][87656922][2][2]);var h=new Date(parseInt(e[1][2][87656922][7]));f.setDate(h.toLocaleString());var i=e[1][2][87656922][9][2];if(i&&i.length>0){var j=i[0][3][2];f.setBody(j)}var k=e[1][2][87656922][12];if(k)for(var l=0;l<k.length;l++){var m=k[l],n=m[6].replace("=","=").replace("&","&");f.addAttachments([[,m[2],m[1],m[3],,,,,,n]])}b.addMessage(f,e[1][2][87656922][1]),b.addParticipants([[e[1][2][87656922][2][3],e[1][2][87656922][2][2]]]);for(var o=0;o<e[1][2][87656922][3].length;o++)b.addParticipants([[e[1][2][87656922][3][o][3],e[1][2][87656922][3][o][2]]])}}g(b)}}else log.error("bad server response"),g(null,"Bad server response. Check clipper logs for more details")},u.setRequestHeader("Content-Type","application/json"),u.setRequestHeader("X-Framework-Xsrf-Token",h[110][4][36376563][14]),u.setRequestHeader("X-is-bigtop-data","True"),u.send(r)}}),this.getThread=c,Object.preventExtensions(this)}Object.preventExtensions(GmailClipper);