/*! Copyright 2009-2017 Evernote Corporation. All rights reserved. */

define(["domReady!"],function(){function a(){if(void 0!==document.hidden&&(c=!document.hidden||c),c){for(var b=0;b<d.length;b++)d[b](document);d=[],void 0!==document.hidden&&document.removeEventListener("visibilitychange",a)}}function b(a){c?a(document):d.push(a)}var c=!0;void 0!==document.hidden&&(c=!document.hidden);var d=[];return c||void 0!==document.hidden&&document.addEventListener("visibilitychange",a),{version:"1.0.0",load:function(a,c,d,e){b(d)}}});