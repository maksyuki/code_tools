/*! Copyright 2009-2017 Evernote Corporation. All rights reserved. */

function Veil(){"use strict";function a(a){if(a.target!==document.documentElement&&l&&l.style&&(l.style.top=a.clientY+"px",l.style.left=a.clientX+"px",n)){var b,c,d,e;b=Math.min(a.clientX,n.x),c=Math.min(a.clientY,n.y),d=Math.max(a.clientX,n.x),e=Math.max(a.clientY,n.y),o.style.borderTopWidth=c+"px",o.style.borderRightWidth=window.innerWidth-d+"px",o.style.borderBottomWidth=window.innerHeight-e+"px",o.style.borderLeftWidth=b+"px"}}function b(a){a.target!==document.documentElement&&1===a.which&&(document.body.style.overflowY="hidden",document.body.style.overflowX="hidden",n={x:a.clientX,y:a.clientY},m&&m.parentNode&&m.parentNode.removeChild(m),Browser.sendToExtension({name:"bounce",message:{name:"goToSkitchWaitingMode"}}),o.style.borderTopWidth=n.y+"px",o.style.borderRightWidth=window.innerWidth-n.x+"px",o.style.borderBottomWidth=window.innerHeight-n.y+"px",o.style.borderLeftWidth=n.x+"px")}function c(a){if(a.target!==document.documentElement&&1===a.which){var b={x:Math.min(a.clientX,n.x),y:Math.min(a.clientY,n.y)},c={x:Math.max(a.clientX,n.x),y:Math.max(a.clientY,n.y)};a.clientX===c.x?(c.x--,b.x++):(b.x++,c.x--),a.clientY===c.y?(c.y--,b.y++):(b.y++,c.y--),c.x-b.x+1<16&&c.y-b.y+1<16?setTimeout(function(){new Audio(Browser.extension.getURL("skitch/sounds/snap.wav")).play(),Browser.sendToExtension({name:"captureScreenshot"})},500):(new Audio(Browser.extension.getURL("skitch/sounds/snap.wav")).play(),Browser.sendToExtension({name:"captureScreenshot",start:b,end:c,screenshotHeight:window.innerHeight})),i(),h()}}function d(){e(),l||(l=document.createElement("div"),l.id="evernoteClipperCrosshair"),m||(m=document.createElement("iframe"),m.id="evernoteClipperCrosshairToast",m.src=Browser.extension.getURL("content/tooltips/screenshot_toast.html")),document.documentElement.appendChild(l),document.documentElement.appendChild(m),setTimeout(function(){m&&m.parentNode&&Browser.sendToExtension({name:"getPersistentValue",key:"sawScreenshotToast"})},3e3),window.addEventListener("mousemove",a),window.addEventListener("mousedown",b),window.addEventListener("mouseup",c)}function e(){l&&l.parentNode&&l.parentNode.removeChild(l),m&&m.parentNode&&m.parentNode.removeChild(m),window.removeEventListener("mousemove",a),window.removeEventListener("mousedown",b),window.removeEventListener("mouseup",c),n=null}function f(a,b,c){function d(a){"opacity"===a.propertyName&&m&&m.parentNode&&(m.removeEventListener(Browser.whichTransitionEnd(),d),m.classList.remove("evernoteClipperHidden"),m.parentNode.removeChild(m))}"sawScreenshotToast"===a.key&&(a.value&&a.value[a.currentUserId]?m&&m.parentNode&&(m.addEventListener(Browser.whichTransitionEnd(),d),m.classList.add("evernoteClipperHidden")):(a.value||(a.value={}),a.value[a.currentUserId]=!0,Browser.sendToExtension({name:"setPersistentValue",key:"sawScreenshotToast",value:a.value}))),c&&"function"==typeof c&&c()}function g(a,b,c){Browser.sendToExtension({name:"bounce",message:{name:"goToSkitchWaitingMode"}}),setTimeout(function(){new Audio(Browser.extension.getURL("skitch/sounds/snap.wav")).play(),Browser.sendToExtension({name:"captureScreenshot"})},500),i(),h(),c&&"function"==typeof c&&c()}function h(){o&&o.parentNode&&o.parentNode.removeChild(o)}function i(){e(),o.style.borderTopWidth="0",o.style.borderRightWidth="0",o.style.borderBottomWidth=window.innerHeight+"px",o.style.borderLeftWidth="0"}function j(a){o.style.borderColor=a}function k(){document.documentElement.appendChild(o)}var l,m,n=null,o=document.createElement("div");o.style.width="100%",o.style.height="100%",o.style.boxSizing="border-box",o.style.top="0",o.style.left="0",o.style.position="fixed",o.style.borderStyle="solid",o.style.borderWidth="0",o.style.zIndex="2147483646",Browser.addMessageHandlers({receivePersistentValue:f,captureScreen:g}),this.enableCrosshair=d,this.disableCrosshair=e,this.removeVeil=h,this.reset=i,this.setColor=j,this.showVeil=k,Object.preventExtensions(this)}Object.preventExtensions(ContentVeil);