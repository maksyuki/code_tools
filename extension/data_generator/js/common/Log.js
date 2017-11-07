/*! Copyright 2009-2017 Evernote Corporation. All rights reserved. */

function FSLogWriter(a){"use strict";function b(){var a=new Date,b=a.getFullYear().toString(),c=(a.getMonth()+1).toString(),d=a.getDate().toString();return 1==c.length&&(c="0"+c),1==d.length&&(d="0"+d),b+"-"+c+"-"+d}function c(){return"en_log_"+b()+".log"}function d(a,b){return(new Date).toTimeString()+" ("+a+") "+b+"\r\n"}function e(a){-1==z.indexOf(a)&&(z.push(a),Persistent.set(x,z),z.length>y&&g())}function f(a){A=!1,console.error("Failed to delete file!",a.code),setTimeout(g,36e5)}function g(){!A&&z.length>y&&(A=!0,t?t.getFile(z[0],{create:!1},h,f):s.root.getFile(z[0],{create:!1},h,f))}function h(a){a.remove(i,f)}function i(){z.shift(),Persistent.set(x,z),A=!1,g()}function j(b){s=b,a?s.root.getDirectory(a,{create:!0},function(a){t=a,g(),m()},k):(g(),m())}function k(a){SAFARI||EDGE||FIREFOX?console.warn("FileSystem unsupported"):console.error("Failed to init FileSystem. Logs will not be saved."),u=!1}function l(a,b){u&&(w.push([a,b]),m())}function m(){s&&w.length&&!v&&(v=!0,o())}function n(){console.warn("Error looking up file."),m()}function o(){var a=w.shift(),b=a[0],d=a[1],f=c();e(f),t?t.getFile(f,{create:!0},function(a){p(a,b,d)},n):s.root.getFile(f,{create:!0},function(a){p(a,b,d)},n)}function p(a,b,c){a.createWriter(function(a){q(a,b,c)},n)}function q(a,b,c){a.onwriteend=r,a.onerror=r,a.seek(a.length);var e=new Blob([d(b,c)],{type:"text/plain"});a.write(e)}function r(a){v=!1,m()}var s=null,t=null,u=!0,v=!1,w=[],x="logFileList";a&&(x=a+"LogFileList");var y=31,z=Persistent.get(x);z||(z=[]);var A=!1;SAFARI||EDGE||FIREFOX?k():webkitRequestFileSystem(PERSISTENT,Log.maxLogSize,j,k),this.write=l,Object.preventExtensions(this)}function LocalStorageLogWriter(){"use strict";function a(a,b){return(new Date).toTimeString()+" ("+a+") "+b+"\r\n"}function b(b,f){if(e){for(;d.length>=Log.maxLogEntries;)d.shift();d.push(a(b,f)),c()}}function c(){Persistent.set(Log.localStorageName,d)}var d=[],e=!0;d=Persistent.get(Log.localStorageName),Array.isArray(d)||(d=[]),this.write=b,Object.preventExtensions(this)}function LogDispatcher(){"use strict";function a(a,b,c){Browser.sendToExtension({name:a,message:b,path:f,error:c.message+" /n"+c.stack})}function b(b){a("log_error",b,new Error)}function c(b){a("log_exception",b,new Error)}function d(b){a("log_log",b,new Error)}function e(b){a("log_warn",b,new Error)}var f=document.location.href.replace(/^.*?:\/\/\w+(\/.*?)(\?.*)?$/,"$1");this.error=b,this.exception=c,this.log=d,this.warn=e,Object.preventExtensions(this)}function LogReceiver(){"use strict";function a(a,b,c){g(a.message,a.path,{stack:a.error}),c&&"function"==typeof c&&c()}function b(a,b,c){h(a.message,a.path,{stack:a.error}),c&&"function"==typeof c&&c()}function c(a,b,c){i(a.message,a.path,{stack:a.error}),c&&"function"==typeof c&&c()}function d(a,b,c){j(a.message,a.path,{stack:a.error}),c&&"function"==typeof c&&c()}function e(a,b,c,d,e){b=b||p;var g=null;"string"!=typeof a&&(e?(a.filename&&(g=a.filename.replace(/^(chrome|safari)-extension:\/\/\w+/,"")),a=a.stack||a.trace||JSON.stringify(a)):a=a+": "+JSON.stringify(a));var h=b+": "+a;return e&&(h+=" at "+g),c&&(d||(h+="\r\n"),h+=f(c,d)),h}function f(a,b){if(!a||!a.stack)return"";var c=a.stack.split(/\n+/);c.length>2&&(c.shift(),c.shift());for(var d=0;d<c.length;d++)c[d]=c[d].replace(/^(.*\()(chrome|safari)-extension:\/\/\w+(\/.*)$/,"$1$3");return b?(c[0].match(/^\s+at\s+(chrome|safari)-extension/)&&(c[0]=c[0].replace(/^\s+(at)\s+(chrome|safari)-extension:\/\/\w+(\/.*)$/," $1 $3")),c[0]):c.join("\r\n")}function g(a,b,c){var d=e(a,b,c);Log.useConsole&&console.error(d),o&&o.write("ERROR",d)}function h(a,b){var c=e(a,b,!1,!0,!0);Log.useConsole&&console.error(c),o&&o.write("EXCEPTION",c)}function i(a,b,c){var d=e(a,b,c,!0);Log.useConsole&&console.log(d),o&&o.write("LOG",d)}function j(a,b,c){var d=e(a,b,c);Log.useConsole&&console.warn(d),o&&o.write("WARN",d)}function k(a){g(a,null,new Error)}function l(a){h(a,null)}function m(a){i(a,null,new Error)}function n(a){j(a,null,new Error)}var o;o=SAFARI||EDGE||FIREFOX?new LocalStorageLogWriter:new FSLogWriter;var p=document.location.href.replace(/^.*?:\/\/\w+(\/.*?)(\?.*)?$/,"$1");Browser.addMessageHandlers({log_error:a,log_exception:b,log_log:c,log_warn:d}),this.error=k,this.exception=l,this.log=m,this.warn=n,Object.preventExtensions(this)}var Log={useConsole:!0,maxLogSize:104857600,localStorageName:"Log_data"};(SAFARI||EDGE||FIREFOX)&&(Log.useConsole=!0,Log.maxLogEntries=512),Object.preventExtensions(Log),Object.preventExtensions(FSLogWriter),Object.preventExtensions(LocalStorageLogWriter),Object.preventExtensions(LogDispatcher),Object.preventExtensions(LogReceiver);var log;document.location.href.match(/background\.html$/)||(log=new LogDispatcher);