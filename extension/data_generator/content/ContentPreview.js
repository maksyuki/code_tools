/*! Copyright 2009-2017 Evernote Corporation. All rights reserved. */

define(["GlobalUtils","PageInfo"],function(a,b){function c(){Ba.parentNode||document.documentElement.appendChild(Ba);var a=window.getComputedStyle(Ba,""),b=parseInt(a.getPropertyValue("width")),c=parseInt(a.getPropertyValue("height"));b&&c&&(Ba.style.marginLeft=0-b/2+"px",Ba.style.marginTop=0-c/2+"px"),ma.fixPosition(!0)}function d(){ma.fixPosition(!1),Ba.parentNode&&Ba.parentNode.removeChild(Ba)}function e(c,d,e,f,g){var h,i,j={"http://localhost/favicon.ico":!0},k=a.createTitleAndLinkPortionOfUrlClipContent(c,d),l=k.content,m=k.textPortion,n=k.link,o=k.url,p=document.createElement("div"),q=document.createElement("img"),r=document.createElement("img"),s=document.createElement("div");if(""!=f.trim()&&(f.length<500?s.textContent=f:s.textContent=f.slice(0,500)+"...",s.style.fontFamily="Helvetica, Arial, sans-serif",s.style.fontSize="12px",s.style.color="#0C0C0C",s.style.display="block",s.style.whiteSpace="normal",s.style.marginTop="15px",s.style.maxHeight="154px",s.style.overflow="hidden",m.appendChild(s)),b.getThumbnail(function(a){if(h=!0,a.src){p.style.position="relative",p.style.display="inline-block",p.style.margin="15px 30px 0px 0px",p.style.overflow="hidden",p.style.verticalAlign="top",q.setAttribute("thumbnail",a.src),va=q,Browser.sendToExtension({name:"cropImage",url:a.src,cropToWidth:150,cropToHeight:150}),q.style.maxWidth="none",q.style.maxHeight="none",q.style.verticalAlign="top",q.style.margin="0",q.style.padding="0",p.appendChild(q),m.parentNode?l.insertBefore(p,m):l.appendChild(p)}i&&g(l)}),e&&!j[e.toLowerCase()])r.onload=function(){i=!0,r.style.display="inline-block",r.style.border="none",r.style.width="16px",r.style.height="16px",r.style.padding="0px",r.style.margin="0px 8px -2px 0px",r.width="16",r.height="16",n.insertBefore(r,o),h&&g(l)},r.onerror=function(){i=!0,h&&g(l)},r.src=e;else if(i=!0,h)return l}function f(a,b,c){va&&(a.datauri?(va.src=a.datauri,va.width=a.width,va.height=a.height,va.removeAttribute("thumbnail")):(va.parentNode.parentNode.removeChild(va.parentNode),va=null)),c&&"function"==typeof c&&c()}function g(a,d,f){function g(a){Ba.innerHTML="",Ba.appendChild(a),c()}la=!1;var i=b.getUrl();h(),ma.gray(),b.getSnippet(function(a){var d=e(b.getTitle(),i,b.getFavIconUrl(),a,g);d&&(Ba.innerHTML="",Ba.appendChild(d),c())}),f&&"function"==typeof f&&f()}function h(a,b,c){document.body.style.overflowY="",document.body.style.overflowX="",ma.reset(),ma.hide(),na.reset(),na.removeVeil(),d(),T(),r(),l(),u(),c&&"function"==typeof c&&c()}function i(){ya=null,za=null,Aa=null,ta&&ta.parentNode&&(ta.parentNode.removeChild(ta),document.documentElement.classList.remove("clearlyBeforeVisible")),U(),FIREFOX&&(pa=null,sa=null)}function j(a){a=a||null,ra&&ra.highlight__deleteAllHighlights(a),qa&&qa.highlight__deleteAllHighlights(a)}function k(a){callbacks={highlightAdded:function(){Browser.sendToExtension({name:"trackEvent",category:"Highlight",action:a})}},"simplified"===a?(ra||(ra={settings:{path:Browser.extension.getURL("clearly/highlight/")},window:pa.iframe.contentWindow,jQuery:window.jQuery},ra=initClearlyComponent__highlight(ra),ra.insertCSS(),ra.addMouseHandlers(),EDGE||(pa.iframe.contentWindow.clearlyHighlight=ra)),ra.callbacks=callbacks,ra.enable()):(qa||(qa={settings:{path:Browser.extension.getURL("clearly/highlight/")},window:window,jQuery:window.jQuery},qa=initClearlyComponent__highlight(qa),qa.insertCSS(),qa.addMouseHandlers()),qa.callbacks=callbacks,qa.enable())}function l(){qa&&qa.disable(),pa&&pa.iframe.contentWindow.clearlyHighlight&&pa.iframe.contentWindow.clearlyHighlight.disable()}function m(a){if(ua=window.pageYOffset,wa){var c;if(void 0!==b&&(c=b.getSelectionFrame()),c){var d={width:c.width,height:c.height,top:c.offsetTop,bottom:c.height+c.offsetTop,left:c.offsetLeft,right:c.width+c.offsetLeft};ma.revealStaticRect(ma.expandRect(d,-9),c,!0),ma.show()}else ma.outlineElement(wa,a,!0);k("article")}else log.warn("Couldn't find a preview element. We should switch to 'full page' mode.")}function n(a,c,d){if(la=!0,window.focus(),h(),wa){var e=wa.getBoundingClientRect();(!e||e&&0==e.width&&0==e.height)&&(wa=null)}wa?(m(a.scrollToElement),xa>1&&ma.setPageCount(xa-1)):b.getDefaultArticle(function(a){wa=a,m(!0),b.getNextPages(function(a,b){(xa=Math.max(a.length,b.length))>1&&ma.setPageCount(xa-1)})}),d&&"function"==typeof d&&d()}function o(a,b,c){la=!1,window.focus(),h(),pa?p():q(),c&&"function"==typeof c&&c()}function p(){document.body.classList.add("clearlyBeforeVisible"),document.documentElement.classList.add("clearlyBeforeVisible"),pa.iframe.classList.add("evernoteClipperVisible"),k("simplified")}function q(){pa={callbacks:{frameCreated:function(){pa.applyUnencodedOptions(pa.defaultThemes.newsprint),pa.loadGoogleFontsRequiredByAppliedOptions(),pa.iframe.addEventListener(Browser.whichTransitionEnd(),function(a){"width"===a.propertyName&&(this.classList.contains("evernoteClipperVisible")?(document.body.classList.add("clearlyVisible"),document.documentElement.classList.add("clearlyVisible"),pa.iframe.contentDocument.body.classList.add("clearlyWaiting"),0==pa.pagesCount?b.getDefaultArticle(function(a,c){pa.addNewPage(c,window.location.href),pa.iframe.contentDocument.body.classList.add("clearlyReady"),b.getNextPages(function(a,b){for(var c=pa.pagesCount;c<b.length;c++)pa.addNewPage(b[c],window.location.href)})}):pa.iframe.contentDocument.body.classList.add("clearlyReady")):(document.body.classList.remove("clearlyVisible","clearlyBeforeVisible"),document.documentElement.classList.remove("clearlyVisible","clearlyBeforeVisible")))});var a=pa.iframe.contentDocument.createElement("link");a.rel="stylesheet",a.href=Browser.extension.getURL("clearly/reformat/css/additional.css"),pa.iframe.contentDocument.body.appendChild(a),pa.iframe.contentWindow.loading=pa.iframe.contentDocument.createElement("div"),pa.iframe.contentWindow.loading.id="loading",pa.iframe.contentDocument.body.appendChild(pa.iframe.contentWindow.loading),p()}},settings:{path:Browser.extension.getURL("clearly/reformat/"),pageLabel:function(a){return Browser.i18n.getMessage("page",[a.toString()])},onCreateFrameUseThisId:"evernoteClearlyArticle",onCreateFrameDoNotInsertCSS:!0,onCreateFrameUseThisURLAsTheLocation:FIREFOX?Browser.getExtensionURL("iframe_stub.html"):""},window:window,jQuery:window.jQuery},pa=initClearlyComponent__reformat(pa),pa.createFrame()}function r(){pa&&pa.iframe&&(pa.iframe.contentDocument.body.classList.remove("clearlyWaiting","clearlyReady"),pa.iframe.classList.remove("evernoteClipperVisible"))}function s(){return pa}function t(a,c,d){if(la=!1,window.focus(),j(),h(),ta&&ta.parentNode)ta.classList.remove("evernoteClipperHidden"),document.documentElement.classList.add("clearlyBeforeVisible");else{var e=document.createElement("div");e.classList.add("evernoteLargeLoading"),document.documentElement.appendChild(e),sa?sa.createFrame():"function"==typeof initClearlyComponent__reformat_custom?(sa={callbacks:{frameCreated:function(){ta=sa.iframe,document.documentElement.classList.add("clearlyBeforeVisible"),Browser.sendToExtension({name:"getPersistentValue",key:b.getCustomFormatSiteName(b.isCustomFormat().id)+"UncheckedSections"})}},settings:{path:Browser.extension.getURL("clearly/reformat_custom/"),cssFontsFile:Browser.extension.getURL("content/"+(SAFARI?"safari":"chrome")+"_fonts.css"),onCreateFrameDoNotInsertCSS:!0,onCreateFrameUseThisId:"evernoteClearlyCustom",onCreateFrameUseThisURLAsTheLocation:FIREFOX?Browser.getExtensionURL("iframe_stub.html"):""},window:window,jQuery:jQuery},sa=initClearlyComponent__reformat_custom(sa),sa?sa.createFrame():log.warn("could not initialize clearly custom reformat")):log.warn("could not find clearly custom reformat")}d&&"function"==typeof d&&d()}function u(){ta&&ta.parentNode&&(ta.classList.add("evernoteClipperHidden"),document.documentElement.classList.remove("clearlyBeforeVisible"))}function v(){return sa.getContentToSaveNode()}function w(){return sa.getUncheckedSections()}function x(a){sa&&sa.setUncheckedSections(b.isCustomFormat().id,a)}function y(){for(var a=document.getElementsByClassName("evernoteLargeLoading");a.length;){var b=a[0];b.parentNode.removeChild(b)}}function z(a,b){if(!a)return log.warn("Can't determine if 'null' is interesting (it's probably not)."),!1;if(a===window.document)return!1;if(""==a.textContent.trim()&&0===a.getElementsByTagName("img").length)return!1;var c=a.getBoundingClientRect();if(!c.width||!c.height)return!1;var d=getComputedStyle(a);return"hidden"!==d.visibility&&"none"!==d.display&&(!a.parentNode||!b.parentNode||a.parentNode!=b&&b.parentNode!=a||!A(a,b))}function A(a,b){var c=a.getBoundingClientRect(),d=b.getBoundingClientRect();return(c.bottom!=d.bottom||c.height!=d.height||c.left!=d.left||c.right!=d.right||c.top!=d.top||c.width!=d.width)&&((a.textContent!==b.textContent||a.getElementsByTagName("img").length!==b.getElementsByTagName("img").length)&&void 0)}function B(a){for(var b=0;b<a.children.length;b++){if(A(a.children[b],a))return B(a.children[b]);if(z(a.children[b],a))return a.children[b]}return a}function C(){return wa}function D(a){function c(){var a=Ba.querySelector("[thumbnail]");a&&a.parentNode.parentNode.removeChild(a.parentNode);for(var b=new XMLSerializer,c="",d=0;d<Ba.children.length;d++)c+=b.serializeToString(Ba.children[d]);return c.replace(/\sxmlns=(?:'[^']+'|"[^"]+")/gi,"")}if(Ba.innerHTML)return c();b.getSnippet(function(d){var f=e(b.getTitle(),b.getUrl(),b.getFavIconUrl(),d,function(b){b&&(Ba.innerHTML="",Ba.appendChild(b),a(c()))});f&&(Ba.innerHTML="",Ba.appendChild(f),a(c()))})}function E(){for(var a=wa.parentNode;a;){if(z(a,wa)){a.enNudgeDescendToNode=wa,wa=a;break}a=a.parentNode}}function F(){if(wa.enNudgeDescendToNode){var a=wa.enNudgeDescendToNode;delete wa.enNudgeDescendToNode,wa=a}else wa=B(wa)}function G(){if(la){var a=wa;E(),a!==wa&&ma.outlineElement(wa,!1,!0,!0)}}function H(){if(la){var a=wa;F(),a!==wa&&ma.outlineElement(wa,!1,!0,!0)}}function I(){if(la)for(var a=wa.previousElementSibling;a;){if(z(a,wa)){wa=a,ma.outlineElement(wa,!1,!0,!0);break}a=a.previousElementSibling}}function J(){if(la)for(var a=wa.nextElementSibling;a;){if(z(a,wa)){wa=a,ma.outlineElement(wa,!1,!0,!0);break}a=a.nextElementSibling}}function K(){var a=document.body.scrollWidth,b=document.body.scrollHeight;return 0==document.body.scrollHeight&&document.body.children.length>0&&(b=document.body.children[0].scrollHeight),rect={bottom:b-4,top:4,left:4,right:a-4,width:a-8,height:b-8}}function L(a,b,c){la=!1;var d=K();h(),ma.revealStaticRect(d,document.body,null,!0),ma.show(),k("fullpage"),c&&"function"==typeof c&&c()}function M(a,b,c){la=!1,h(),c&&"function"==typeof c&&c()}function N(){var a=document.createElement("div");return a.id="evernoteEmailPreview",a.addEventListener("mousewheel",Browser.overrideScroll,!0),a}function O(a,b,c){h(),U(),Ca=N(),Browser.sendToExtension({name:"bounce",message:{name:"gt_setSaveReady",value:!1}}),ma.reset(),ma.fixPosition(!0),ma.blockMouse(!1),ma.gray(),Ca.innerHTML="";var d=document.createElement("div");d.classList.add("evernoteLargeLoading"),Ca.appendChild(d),V();var e=document.createElement("div"),f=document.createElement("div");f.className="evernoteEmailHeader evernoteEmailBig",e.appendChild(f);var g=document.createElement("div");g.id="evernoteEmailParticipants",g.className="evernoteEmailHeader evernoteEmailSmall",e.appendChild(g);var i=document.createElement("div");i.className="evernoteEmailDivider evernoteEmailLight evernoteEmailLong",e.appendChild(i);var j=document.createElement("div");j.id="evernoteEmailSelectAllMessages",j.className="evernoteEmailHeader evernoteEmailMedium evernoteEmailSelectedMessage";var k=document.createElement("div");k.className="evernoteEmailCheckbox",k.addEventListener("click",function(){var a=document.querySelectorAll(".evernoteEmail");if(/evernoteEmailSelectedMessage/.test(this.parentNode.className))for(var b=0;b<a.length;b++)Q(a.item(b));else for(var b=0;b<a.length;b++)P(a.item(b))}),j.appendChild(k);var l=document.createElement("span");l.innerText=Browser.i18n.getMessage("selectAllMessages"),j.appendChild(l),e.appendChild(j),oa.getThread(function(a,b){if(a){Browser.sendToExtension({name:"bounce",message:{name:"gt_setTitle",title:a.subject}}),f.innerText=a.subject,a.participants&&Object.keys(a.participants).length>0&&(g.innerText=Browser.i18n.getMessage("participants")+": "+Object.keys(a.participants).join(", "));for(var c=0;c<a.messages.length;c++){0!=c&&(i=document.createElement("div"),i.className="evernoteEmailDivider evernoteEmailDark evernoteEmailShort",e.appendChild(i));var d=document.createElement("div");d.className="evernoteEmail evernoteEmailSelectedMessage",k=document.createElement("div"),k.className="evernoteEmailCheckbox",k.addEventListener("click",function(){/evernoteEmailSelectedMessage/.test(this.parentNode.className)?Q(this.parentNode):P(this.parentNode)}),d.appendChild(k);var h=document.createElement("div"),j=document.createElement("span");j.className="evernoteEmailHeader evernoteEmailMedium",j.innerText=a.messages[c].author.name+" ",h.appendChild(j);var l=document.createElement("span");l.className="evernoteEmailDimmed evernoteEmailSmall evernoteEmailRight",l.innerText=a.messages[c].date,h.appendChild(l),d.appendChild(h);var m=document.createElement("div");if(m.className="evernoteEmailBody",m.innerHTML=a.messages[c].body,d.appendChild(m),a.messages[c].attachments.length>0){var n=document.createElement("div");n.className="evernoteEmailAttachments";for(var o=0;o<a.messages[c].attachments.length;o++){var p=document.createElement("div"),q=document.createElement("input");q.type="checkbox",q.checked="true",q.addEventListener("click",function(){this.parentNode.getAttribute("evernoteIgnoreAttachment")?R(this.parentNode):S(this.parentNode)});var r=document.createElement("span");r.className="evernoteEmailSmall";var s=document.createElement("span");s.className="evernoteEmailDimmed evernoteEmailSmall evernoteEmailSize",r.textContent=a.messages[c].attachments[o].name,s.textContent="("+a.messages[c].attachments[o].size+")",p.setAttribute("evernote_attachment_url",a.messages[c].attachments[o].url),p.setAttribute("evernote_attachment_name",r.textContent),p.setAttribute("evernote_attachment_mime",a.messages[c].attachments[o].mime),p.appendChild(q),p.appendChild(r),p.appendChild(s),n.appendChild(p)}d.appendChild(n)}e.appendChild(d)}y(),Ca.appendChild(e)}else log.warn(b),e.innerText=0===b?Browser.i18n.getMessage("Error_Network_Unavailable"):Browser.i18n.getMessage("unableOpenEmail"),e.classList.add("error-block"),y(),Ca.appendChild(e);Browser.sendToExtension({name:"bounce",message:{name:"gt_setSaveReady",value:!0}})}),c&&"function"==typeof c&&c()}function P(a){a.className+=" evernoteEmailSelectedMessage";var b=a.children[1].firstElementChild;b.className=b.className.replace(/\s*evernoteEmailDimmed/g,""),document.querySelectorAll(".evernoteEmail").length===document.querySelectorAll(".evernoteEmail.evernoteEmailSelectedMessage").length&&(document.querySelector("#evernoteEmailSelectAllMessages").className+=" evernoteEmailSelectedMessage")}function Q(a){a.className=a.className.replace(/\s*evernoteEmailSelectedMessage/g,""),a.children[1].firstElementChild.className+=" evernoteEmailDimmed";var b=document.querySelector("#evernoteEmailSelectAllMessages");b.className=b.className.replace(/\s*evernoteEmailSelectedMessage/g,"")}function R(a){a.removeAttribute("evernoteIgnoreAttachment")}function S(a){a.setAttribute("evernoteIgnoreAttachment","true")}function T(){Ca&&(Ca.style.display="none")}function U(){Ca.parentNode&&Ca.parentNode.removeChild(Ca)}function V(){Ca.parentNode||document.documentElement.appendChild(Ca),Ca.style.display="block"}function W(){if(Ca){for(var a=Ca.firstElementChild,c=a.querySelectorAll('.evernoteEmailCheckbox, #evernoteEmailSelectAllMessages, .evernoteEmail:not(.evernoteEmailSelectedMessage), [evernoteignoreattachment="true"]'),d=0;d<c.length;d++)if(c.item(d).parentNode){if(c.item(d).matchesSelector&&c.item(d).matchesSelector(".evernoteEmail")||c.item(d).msMatchesSelector&&c.item(d).msMatchesSelector(".evernoteEmail")){var e=c.item(d).previousElementSibling;e&&/evernoteEmailDivider/.test(e.className)&&/evernoteEmailShort/.test(e.className)||(e=c.item(d).nextElementSibling),e&&e.parentNode&&/evernoteEmailDivider/.test(e.className)&&/evernoteEmailShort/.test(e.className)&&e.parentNode.removeChild(e)}if("evernoteEmailSelectAllMessages"==c.item(d).id){var f=document.createElement("a");f.id="evernoteEmailLinkBack",f.className="evernoteEmailHeader evernoteEmailMedium",f.target="_blank",f.href=document.location.href;var g=document.createElement("div");g.id="evernoteEmailLinkBackArrow",f.appendChild(g);var h=document.createElement("span"),i="";b.isGmailThread()?i=Browser.i18n.getMessage("openConvoInGmail"):b.isGoogleInboxThread()&&(i=Browser.i18n.getMessage("openConvoInGoogleInbox")),h.innerText=i,f.appendChild(h),c.item(d).parentNode.insertBefore(f,c.item(d))}c.item(d).parentNode.removeChild(c.item(d))}var j=a.querySelector(".evernoteEmailDivider.evernoteEmailLong");return j&&(j.className=j.className.replace(/\s*evernoteEmailLong/g," evernoteEmailShort")),a}return null}function X(a,b){var c={top:Math.min(a.top,b.top),bottom:Math.max(a.bottom,b.bottom),left:Math.min(a.left,b.left),right:Math.max(a.right,b.right)};return c.width=c.right-c.left,c.height=c.bottom-c.top,c}function Y(a,b){return!a&&!b||!!a&&(!!b&&(a.top==b.top&&(a.bottom==b.bottom&&(a.left==b.left&&(a.right==b.right&&(a.width==b.width&&a.height==b.height))))))}function Z(a){if(0!==a.endOffset||a.endContainer.nodeType!==Node.ELEMENT_NODE){var b=a.getBoundingClientRect();return{top:b.top,bottom:b.bottom,left:b.left,right:b.right,width:b.width,height:b.height}}var c=null;try{c=a.endContainer.getBoundingClientRect()}catch(a){log.warn("Couldn't get a bounding client rect for our end element, maybe it's a text node.")}for(var d=!1,e=[],f=a.getClientRects(),g=0;g<f.length;g++)Y(c,f[g])&&!d?d=!0:e.push(f[g]);if(0==e.length)return a.getBoundingClientRect();if(1==e.length)return e[0];for(var b=e[0],g=1;g<e.length;g++)b=X(b,e[g]);return b}function $(a){return"rtl"!=document.dir&&(!(a.bottom<0&&a.top<0)&&!(a.left<0&&a.right<0))}function _(a,b){var c=b,d=a.getBoundingClientRect();if(d={bottom:d.bottom+window.scrollY,height:d.height,left:d.left+window.scrollX,right:d.right+window.scrollX,top:d.top+window.scrollY,width:d.width},!$(d))return c;var e=getComputedStyle(a);if("none"==e.display)return c;if("hidden"==e.overflowX||"hidden"==e.overflowY)return c;if(d.width*d.height>1&&(c=X(d,b)),a.children)for(var f=0;f<a.children.length;f++)c=_(a.children[f],c);return c}function aa(a,b){if(b)return K();if(!a)return{top:0,bottom:0,left:0,right:0,width:0,height:0};var c=a.getBoundingClientRect();return _(a,{bottom:c.bottom+window.scrollY,height:c.height,left:c.left+window.scrollX,right:c.right+window.scrollX,top:c.top+window.scrollY,width:c.width})}function ba(){var a;if(void 0!==typeof b&&!ya){a=b.getSelection(),ya=[],za=[];for(var c=0;c<a.rangeCount;c++)ya.push(a.getRangeAt(c).cloneRange()),za.push([ya[c].startOffset,ya[c].endOffset]);Aa=b.getSelectionFrame()}if(!a){a=window.getSelection(),a.removeAllRanges();for(var d=0;d<ya.length;d++){var e=document.createRange();if((ya[d].startContainer.length||ya[d].startContainer.childNodes.length)<za[d][0])for(var f=0,c=0;c<ya[d].startContainer.childNodes.length;c++){var g=ya[d].startContainer.childNodes[c],h=0;if(h=g.getAttribute&&g.getAttribute("clearly_highlight_id")?(g.innerText||g.textContent).length:g.length||g.childNodes.length,(f+=h)>=za[d][0]){e.setStart(g,za[d][0]-(f-h));break}}else e.setStart(ya[d].startContainer,za[d][0]);if((ya[d].endContainer.length||ya[d].endContainer.childNodes.length)<za[d][1])for(var f=0,c=0;c<ya[d].endContainer.childNodes.length;c++){var g=ya[d].endContainer.childNodes[c],h=0;if(h=g.getAttribute&&g.getAttribute("clearly_highlight_id")?(g.innerText||g.textContent).length:g.length||g.childNodes.length,(f+=h)>=za[d][1]){e.setEnd(g,za[d][1]-(f-h));break}}else e.setEnd(ya[d].endContainer,za[d][1]);a.addRange(e)}}return a}function ca(a,b,c){ua&&window.scrollTo(0,ua),la=!1;var d=ba();ma.reset();var e=null;Aa&&(e=Aa.getBoundingClientRect());var f,g,i,j=[];if(d){for(h(),ma.reset(),i=0;i<d.rangeCount;i++){f=d.getRangeAt(i);var k=Z(f);k.top+=window.pageYOffset,k.bottom+=window.pageYOffset,k.left+=window.pageXOffset,k.right+=window.pageXOffset,e&&(k.left+=e.left,k.right+=e.left,k.top+=e.top,k.bottom+=e.top),j.push(k)}d.rangeCount&&(g=da(j),ma.revealStaticRect(g,Aa,!1),ma.show())}ma.show(),c&&"function"==typeof c&&c()}function da(a){for(var b=Object.assign({},a[0]),c=1;c<a.length;c++)b.top=Math.min(a[c].top,b.top),b.left=Math.min(a[c].left,b.left),b.bottom=Math.max(a[c].bottom,b.bottom),b.right=Math.max(a[c].right,b.right);return b.height=b.bottom-b.top,b.width=b.right-b.left,b}function ea(a,b){var c=parseFloat(ma.getElement().style.borderTopWidth),d=parseFloat(ma.getElement().style.borderRightWidth),e=parseFloat(ma.getElement().style.borderBottomWidth),f=parseFloat(ma.getElement().style.borderLeftWidth),g=parseFloat(ma.getElement().style.width),h=parseFloat(ma.getElement().style.height);return!(a<g-d&&a>f&&b>c&&b<h-e)}function fa(a){h(),ma.reset(),ma.gray(a)}function ga(a){wa=a}function ha(a,b,c){ua&&window.scrollTo(0,ua),fa("transparent"),na.reset(),na.showVeil(),na.setColor("rgba(0, 0, 0, 0.27)"),na.enableCrosshair(),c&&"function"==typeof c&&c()}function ia(a,c,d){a.key===b.getCustomFormatSiteName(b.isCustomFormat().id)+"UncheckedSections"&&(a.value&&a.value[a.currentUserId]&&x(a.value[a.currentUserId]),b.getCustomFormatReformattedData(function(a){y(),sa.displayDetected(a)})),d&&"function"==typeof d&&d()}function ja(a,b,c){h(),c&&"function"==typeof c&&c()}var ka={},la=!1,ma=new ContentVeil,na=new Veil,oa=new GmailClipper,pa=null,qa=null,ra=null,sa=null,ta=null;b.isGmail()&&function(){for(var a="",b=["#evernoteEmailPreview .evernoteEmailHeader, #evernoteEmailPreview .evernoteEmailDimmed, #evernoteEmailPreview .evernoteEmailAttachments","#evernoteEmailPreview .evernoteEmailHeader","#evernoteEmailPreview .evernoteEmailBig","#evernoteEmailPreview .evernoteEmailMedium","#evernoteEmailPreview .evernoteEmailSmall","#evernoteEmailPreview .evernoteEmailRight","#evernoteEmailPreview .evernoteEmailDimmed","#evernoteEmailPreview .evernoteEmailDivider","#evernoteEmailPreview .evernoteEmailLight","#evernoteEmailPreview .evernoteEmailDark","#evernoteEmailPreview .evernoteEmailLong","#evernoteEmailPreview .evernoteEmailShort","#evernoteEmailParticipants","#evernoteEmailLinkBack","#evernoteEmailLinkBackArrow","#evernoteEmailPreview .evernoteEmail","#evernoteEmailPreview .evernoteEmailBody","#evernoteEmailPreview .evernoteEmailAttachments","#evernoteEmailPreview .evernoteEmailAttachments .evernoteEmailSize"],c=["font-family: Helvetica, Arial, sans-serif !important;","color: #333333 !important; font-weight: bold !important;","font-size: 15px !important;","font-size: 14px !important;","font-size: 12px !important;","float: right !important;","color: #888888 !important;","height: 1px !important;","background-color: #E9E9E9 !important;","background-color: #B3B3B3 !important;","left: -48px !important; position: relative !important; width: calc(100% + 96px) !important;","width: 100% !important;","margin: 16px 0 29px 0 !important;","display: block; margin: 22px 0 8px 0 !important; position: relative !important; text-decoration: none !important;","background-image: url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAALCAYAAAB24g05AAAAr0lEQVQoU2NkwAKMjY35gcLTzp49G41NHlmMEV2BgYGBNRMT0xJGRkYFoAEY8ujqkRWwGBoa1gI1VwMVMYMUEm2Arq6uEisr62KgrVbINhBlgJGRUQxQ41SgRj5C/sUmzwh0dhzQ2ZPJNgBkKtQLS4EusSDWC8CY+g9SixKIQME6oFgVMYGIzQCw5UAJm////4OiUR5fIOI0AGoIP9CQGefOnYvEFbB4DSAmNmAGAABi7TE0OfL+0wAAAABJRU5ErkJggg==) !important;background-repeat: no-repeat !important; background-size: 16px 11px !important;display: inline-block; height: 11px !important; margin-right: 12px; width: 16px !important;","margin: 24px 0 !important; position: relative !important;","color: #222; font-family: Arial, sans-serif; font-size: 13px; margin-top: 24px !important;","padding: 20px 0 0 40px !important;","margin-left: 10px !important;"],d=0;d<b.length;d++)a+=b[d]+"{"+c[d]+"}";var e=document.createElement("style");e.innerText=a,document.head||(document.head=document.createElement("head")),document.head.appendChild(e)}();var ua,va,wa=null,xa=0,ya=null,za=null,Aa=null,Ba=function(){var a=document.createElement("div");return a.addEventListener("mousewheel",Browser.overrideScroll,!0),a.id="evernotePreviewContainer",a.className="evernotePreviewContainer evernotePreviewUrlContainer",a.style.setProperty("line-height","normal","important"),a}(),Ca=N();return Browser.addMessageHandlers({clearPreview:h,previewArticle:n,previewClearly:o,previewCustom:t,previewEmail:O,previewFullPage:L,previewPdf:M,previewSelection:ca,previewSkitch:ha,previewUrl:g,receiveCroppedImage:f,receivePersistentValue:ia,receiveScreenshot:ja}),ka.clear=h,ka.clearHighlights=j,ka.getArticleElement=C,ka.getUrlElement=D,ka.getClearlyReformat=s,ka.getCustomElementContent=v,ka.getCustomElementUncheckedSections=w,ka.looksInteresting=z,ka.computeDescendantBoundingBox=aa,ka.getEmailElement=W,ka.ensureSelectionIsShown=ba,ka.expandPreview=G,ka.contractPreview=H,ka.moveToElementAbove=I,ka.moveToElementBelow=J,ka.isPointOnVeil=ea,ka.reset=i,ka.gray=fa,ka.setElement=ga,ka});