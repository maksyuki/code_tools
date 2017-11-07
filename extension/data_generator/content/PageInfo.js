/*! Copyright 2009-2017 Evernote Corporation. All rights reserved. */

define(["GlobalUtils","isTest","topFrame!pageVisible!"],function(a,b){function c(){if(ta)return ta;for(var a in ka)if(ka[a].regex.test(document.location.href))return a;return null}function d(a){for(var b=a||document,c=b.getElementsByTagName("img"),d=null,e=0,f=0;f<c.length;f++){var g=c[f].width*c[f].height;g>e&&(d=c[f],e=g)}return d}function e(a){var b=a?a[0]:null;a:for(;b;){for(var c=a.length,d=0;d<c;d++)if(!b.contains(a[d])){b=b.parentNode;continue a}break}return b}function f(a){a=a||window;var b=a.location.host;return/^www\./.test(b)&&(b=b.substr(4)),b}function g(a){var a=a||window,b=f(a);if(ha[b]){var c=a.document||document,d=ha[b].join(","),e=c.querySelector(d);if(e)return e}return null}function h(a){var a=a||window,b=f(a);if(ga[b]){var c=a.document||document,d=ga[b].join(","),e=c.querySelector(d);if(e)return e}return null}function j(a){var b=f();if(ia[b]){var c=document.querySelector(ia[b].container);if(c){var g=c.querySelectorAll(ia[b].include);if(g&&g.length>0){for(var i=g[g.length-1].nextElementSibling,j=document.createElement("div"),k=0;k<g.length;k++)j.appendChild(g[k]);return i.parentNode.insertBefore(j,i),j}}}var m=h();if(null!==m)return m;if(-1!=ja.indexOf(b)){var j=d();if(j)return j}if(ta){var j=document.querySelector(ka[ta].content);return j&&""!=j.textContent.trim()||(j=document.createElement("div"),document.body.insertBefore(j,document.body.firstChild)),j}if(/\.(jpe?g|gif|png)$/i.test(location.href)){var n=document.getElementsByTagName("img")[0];if(n&&n.parentNode===document.body)return n}if("frameset"==document.body.nodeName.toLowerCase()){qa=!0;var o=l();if(o&&o.contentDocument&&o.contentDocument.documentElement){ra=o;var j=o.contentDocument.documentElement;if(j)return j}}if(a&&a._elements){var j=e(a._elements);if(j)return j.nodeType===Node.TEXT_NODE&&(j=j.parentNode),j}return document.body}function k(a){var b=FIREFOX?76e4:1048576;document.body.innerHTML.length>b?(log.warn("Page over 1mb, skipping article detection."),la.push(j(null)),ma.push(la[la.length-1].outerHTML),a()):"function"==typeof initClearlyComponent__detect?(aa={callbacks:{finished:function(b){la.push(j(b)),b&&b._html&&ma.push(b._html),a()}},getSpecialCaseArticle:h,getSpecialCandidate:g,window:window,jQuery:window.jQuery},aa=initClearlyComponent__detect(aa),aa?aa.start():(log.warn("failed to initiate clearly detect component"),la.push(j(null)),ma.push(la[la.length-1].outerHTML),a())):(log.warn("Couldn't find clearly detect!"),la.push(j(null)),ma.push(la[la.length-1].outerHTML),a())}function l(){for(var a=document.getElementsByTagName("frame"),b=null,c=0,d=0;d<a.length;d++)if(a[d].width&&a[d].height){var e=a[d].width*a[d].height;e>c&&(b=a[d],c=e)}return b}function m(a){la.length&&la[0].parentNode&&la[0].getBoundingClientRect&&0!=la[0].getBoundingClientRect().width?a(la[0],ma[0]):(n(),k(function(){a(la[0],ma[0])}))}function n(){la=[],ma=[],na=[],oa=!0}function o(a){return a&&na.push(a),oa?(oa=!1,p(function(){q()})):a&&a(la,ma),la}function p(a){"function"==typeof initClearlyComponent__next?(ba={callbacks:{newPageFound:function(b){if(b){var c=e(b._elements);c&&la.push(c),b._html&&ma.push(b._html)}a()}},settings:{onCreateNextPagesContainerUseThisId:"evernoteClearlyNextContainer",onCreateFrameUseThisURLAsTheLocation:FIREFOX?Browser.getExtensionURL("iframe_stub.html"):""},detectComponentInstance:aa},ba=initClearlyComponent__next(ba),ba?(ba.createNextPagesContainer(),ba.start()):(log.warn("failed to initiate clearly next component"),a())):(log.warn("Couldn't find clearly next!"),a())}function q(){for(var a=0;a<na.length;a++)na[a](la,ma)}function r(){var a=s();if(sa=[],a)for(var b=0;b<a.rangeCount;b++){var c=a.getRangeAt(b);sa[b]=c}}function s(){var a=window.getSelection();if(a&&a.rangeCount&&!a.isCollapsed)return a;for(var b=[],c=document.getElementsByTagName("iframe"),d=0;d<c.length;d++)b.push(c[d]);for(var e=document.getElementsByTagName("frame"),d=0;d<e.length;d++)b.push(e[d]);for(var f=document.location.href.replace(/^(https?:\/\/.*?)\/.*/i,"$1").toLowerCase(),d=0;d<b.length;d++)if(!b[d].src||b[d].src.toLowerCase().substr(0,f.length)===f)try{var g=b[d].contentDocument;if(g){var h=g.getSelection();if(h&&h.rangeCount&&!h.isCollapsed)return pa=!0,ra=b[d],h}else log.warn("iframe contained no Document object.")}catch(a){}return null}function t(){var a=window.getSelection();a.removeAllRanges();for(var b=0;b<sa.length;b++)a.addRange(sa[b])}function u(b,c,d,e,f,g){if(b.nodeType==Node.TEXT_NODE){if(e||!ta){var h,i=x(b,f);return h=g?a.removePunctuation(i.trim()).replace(/\s+/g," "):i.trim().replace(/\s+/g," ")," "===h||""===h?c:c+" "+h}return c}var j=["script","noscript","style"];if(b.nodeType==Node.ELEMENT_NODE&&-1==j.indexOf(b.nodeName.toLowerCase())){if(/^evernote.+Tools$/.test(b.id))return c;for(var k=0;k<b.childNodes.length;k++){if(ta){if(w(b.childNodes[k]))continue;c=v(b)||e?f?u(b.childNodes[k],c,d,!0,f,g):u(b.childNodes[k],c,d,!0,b,g):u(b.childNodes[k],c,d,!1,null,g)}else c=u(b.childNodes[k],c,d,!1,null,g);if(c.length>d)return c}}return c}function v(a){var b=ka[ta].allowedElements;return!!(a.matchesSelector&&a.matchesSelector(b)||a.msMatchesSelector&&a.msMatchesSelector(b))}function w(a){var b=ka[ta].bannedSubelements;return!!b&&!!(a.matchesSelector&&a.matchesSelector(b)||a.msMatchesSelector&&a.msMatchesSelector(b))}function x(a,b){var c=a.textContent;if(ta){var d;if("Baidu"==ta?(d=b.parentNode.parentNode.querySelector(".g"))&&(d=d.textContent):"Yandex"==ta||"YandexRU"==ta?(d=b.parentNode.querySelector(".b-serp-item__title-link, .serp-item__title-link"))&&(d=d.href):d=b.href,d){var e={wikipedia:/(.*)[-|\u2013|\u2014]/,youtube:/(.*)[-|\u2013|\u2014]/,facebook:/(.*)\|/,wiktionary:/(.*)-\sWiktionary/,stumbleupon:/(.*)\|\sStumbleUpon\.com/};for(var f in e)if(new RegExp(f).test(d)){var g=e[f],h=g.exec(c);if(h)return b.setAttribute("sawdivider",!0),h[1];if(b.getAttribute("sawdivider"))return""}}if(/(\d+\slikes)|(\d+\stalking\sabout\sthis)/.test(c))return c.replace(/(\d+\slikes)|(\d+\stalking\sabout\sthis)/g," ");if(/Definition from Wiktionary, the free dictionary. Jump to: navigation, search/.test(c))return c.replace(/Definition from Wiktionary, the free dictionary. Jump to: navigation, search/g," ")}return c}function y(){var a=document.title,b=z();if(b)a=b;else{var c=document.querySelector("meta[property='og:title'][content]");c&&(a=c.getAttribute("content"))}if(ta)if(ka[ta].titleTrim)a=ka[ta].titleTrim(a);else{var d=a.split(" - ");a=a.replace(" - "+d[d.length-1],"")}return J()&&(a=FIREFOX?"PDF - "+document.title:"PDF - "+document.domain),a.trim()}function z(){var a=document.querySelector("[itemtype$='VideoObject'] [itemprop='name']");if(a){if(a.hasAttribute("content")&&a.getAttribute("content").trim())return a.getAttribute("content").trim();if(a.textContent&&a.textContent.trim())return a.textContent.trim()}return null}function A(){return"cafe.daum.net"===document.location.hostname?document.location.href:U()||V()||W()||X()||document.location.href}function B(){if(ta){var a=document.querySelector(ka[ta].searchBox);if(a||(a=document.querySelector(ka[ta].searchBoxAlt)),a){var b=a.value.trim();if(b.length>0)return b}}return null}function C(a){var b="",c=D();if(c&&(b=c),!b){var d=document.querySelector("meta[property='og:description'][content]");d&&d.content.trim()&&(b=d.content.trim())}if(!b){var e=document.querySelector("[itemprop='description']");e&&(e.content&&e.content.trim()?b=e.content.trim():e.textContent&&e.textContent.trim()&&(b=e.textContent.trim()))}if(!b){var f=document.querySelector("meta[name='description'][content], meta[name='Description'][content]");f&&(b=f.content.trim())}if(!b){var g=document.querySelectorAll("[itemprop='articleBody']"),h=Array.prototype.map.call(g,function(a){return a.textContent.trim()?a.textContent.trim():""}).join(" ");h.trim()&&(b=h.trim())}b?a(b.substr(0,fa)):m(function(b){a(u(b,"",fa,!1,null,!1))})}function D(){var a=document.querySelector("[itemtype$='VideoObject'] [itemprop='description']");if(a){if(a.hasAttribute("content")&&a.getAttribute("content").trim())return a.getAttribute("content").trim();if(a.textContent&&a.textContent.trim())return a.textContent.trim()}return null}function E(){var a="",b=s();if(b){var c=document.createElement("div");for(i=0;i<b.rangeCount;i++){var d=b.getRangeAt(i).cloneContents();c.appendChild(d)}a=u(c,"",5e3,!1,null,!0)}else a=la.length?u(la[0],"",5e3,!1,null,!0):u(document.body,"",5e3,!1,null,!0);return a=y()+" "+a}function F(){return ra}function G(a,b,c,d){var e=s(),f={url:A(),selection:null!==e||sa.length>0,selectionIsInFrame:pa,recommendationText:E(!1),query:B(),searchEngine:ta,favIconUrl:Y(),documentIsFrameset:qa,pdf:J(),gmailThread:R()||Q(),gmail:O()};d&&d(f)}function H(a){Browser.sendToExtension({name:"simSearch_receivePageInfo",info:a})}function I(a,b,c){"undefined"!=typeof SAFARI&&SAFARI&&!a.sendToTab&&sa.length>0&&null==s()&&t(),k(function(c){G(c,a,b,H)}),c&&"function"==typeof c&&c()}function J(){if(document.querySelector("embed[type='application/pdf']"))return document.querySelector("embed[type='application/pdf']").src;if("pdf.js"===document.domain)return document.location.href;if(/^https?:\/\/docs\.google\.com\/viewer\?url=.+/.test(document.location.href)){for(var a=0;a<document.scripts.length;a++)if(/gviewApp\.setFileData/.test(document.scripts[a].innerText)){if(/mimeType.+application\/pdf/.test(document.scripts[a].innerText)){var b=/^https?:\/\/docs\.google\.com\/viewer\?url=(.+?)(?:$|&)/.exec(document.location.href);return decodeURIComponent(b[1])}break}}else if(X())return X();return null}function K(a){return{linked_in:"linkedin",amazon:"amazon",youtube:"youtube"}[a]}function L(){if(ca)return ca.check();if("function"==typeof initClearlyComponent__detect_custom){if(ca={callbacks:{finished:function(a){da(a)}},jQuery:jQuery,window:window},ca=initClearlyComponent__detect_custom(ca))return ca.check();log.warn("Couldn't initialize clearly custom detect")}else log.warn("Couldn't find clearly custom detect!");return!1}function M(a){da=a,ca.start()}function N(){return/^https:\/\/outlook(-sdf)?\.(office|live)\.com/.test(document.location.href)}function O(){var a=document.location.href;return/^https:\/\/mail\.google\.com\/mail\//.test(a)&&!a.endsWith("undefined")}function P(){return/^https:\/\/inbox\.google\.com/.test(document.location.href)}function Q(){return!!P()&&!!document.querySelector(ga["inbox.google.com"])}function R(){if(O()){if(document.querySelectorAll("span > div > span > [src='images/cleardot.gif']").length>0)return!0;if(document.querySelectorAll("div.bodycontainer > div.maincontent").length>0)return!0}return!1}function S(a){var b="",c=T();if(c)b=c;else{var e=document.querySelector("meta[property='twitter:image'][content]");e?b=e.content:(e=document.querySelector("[itemtype$='ImageObject'] [itemprop='url'][src]"),e?b=e.src:(e=document.querySelector("meta[property='og:image'][content]"))&&(b=e.content))}b?a({src:b}):m(function(b){var c=d(b);a({src:c?c.src:null})})}function T(){var a=document.querySelector("[itemtype$='VideoObject'] [itemprop='thumbnailUrl'][href]");return a&&a.href.trim()?a.href.trim():null}function U(){var a=document.querySelector("[itemtype$='VideoObject'] [itemprop='url'][href]");return a&&a.href.trim()?a.href.trim():null}function V(){for(var a=["https://github.com/","http://cafe.daum.net/","https://www.everlane.com/"],b=document.location.href,c=!1,d=0;d<a.length;d++)0===b.indexOf(a[d])&&(c=!0);var e=document.querySelector("meta[property='og:url'][content]");if(e&&e.content&&!c){var b=e.content;return/^https?:\/\//i.test(b)||(b=/^\//.test(b)?document.origin+b:document.origin+"/"+b),b}return null}function W(){if(!O()){var a=document.querySelector("link[rel='canonical']");if(a)return a.href}return null}function X(){var a=/^chrome-extension:\/\/(?:encfpfilknmenlmjemepncnlbbjlabkc|oemmndcbldboiebfnladdacbdfmadadm)\/(.+)/.exec(document.location.href);return a?a[1]:null}function Y(){var a=document.querySelector("link[rel~='icon']");return a?a.href:location.origin+"/favicon.ico"}function Z(){return new Promise(function(a,b){Browser.runAfterDomLoaded(function(){var b;switch(document.querySelector("img[data-bttrlazyloading-lg-src], img[data-bttrlazyloading-lg]")?b="bttrLazyLoading":document.querySelector("img.lazyload, img.lazyloaded, img.lazyloading")&&(b="lazysizes"),b){case"bttrLazyLoading":for(var c=document.querySelectorAll("img[data-bttrlazyloading-lg-src], img[data-bttrlazyloading-lg]"),d=0,e=c.length;d<e;d++){var f=c[d];if(!f.getAttribute("src")){var g=f.getAttribute("data-bttrlazyloading-lg-src")||f.getAttribute("data-bttrlazyloading-md-src")||f.getAttribute("data-bttrlazyloading-sm-src")||f.getAttribute("data-bttrlazyloading-xs-src");g||(g=f.getAttribute("data-bttrlazyloading-lg")||f.getAttribute("data-bttrlazyloading-md")||f.getAttribute("data-bttrlazyloading-sm")||f.getAttribute("data-bttrlazyloading-xs"),g=JSON.parse(g).src),f.setAttribute("src",g)}}break;case"lazysizes":for(var c=document.querySelectorAll("img.lazyload, img.lazyloaded, img.lazyloading"),d=0,e=c.length;d<e;d++){var g,f=c[d];g="PICTURE"==f.parentNode.tagName?$(f.parentNode):f.getAttribute("data-src")||_(f.getAttribute("data-srcset")),g?f.setAttribute("src",g):log.warn("Image hasn't atrribute for lazy loading (lazysizes.js library)")}}a()})})}function $(a){for(var b=a.querySelectorAll("source"),c=_(b[0].getAttribute("data-srcset")),d=0;d<b.length;d++)window.matchMedia(b[d].getAttribute("media")).matches&&(c=_(b[d].getAttribute("data-srcset")));return c}function _(a){var b=/(?:[^"'\s,]+\s*(?:\s+\d+[wx])(?:,\s*)?)/gm;return a?a.match(b)?a.match(b)[0].split(" ")[0]:a:null}var aa,ba,ca,da,ea={},fa=510,ga={"tagesspiegel.de":["div.ts-article-area"],"penny-arcade.com":["#comic img"],"io9.gizmodo.com":["div.main__content"],"aspicyperspective.com":["div.entry-content"],"reddit.com":["#siteTable"],"thewirecutter.com":["div#content"],"katespade.com":["div#pdpMain"],"threadless.com":["section.product_section"],"yelp.com":["div#bizBox"],"flickr.com":["div#photo"],"instagr.am":["div.stage > div.stage-inner"],"stackoverflow.com":["#mainbar"],"makeprojects.com":["div#guideMain"],"cookpad.com":["div#main #recipe"],"imgur.com":["div.image"],"smittenkitchen.com":["div.entry"],"allrecipes.com":["div#content-wrapper"],"qwantz.com":["img.comic"],"questionablecontent.net":["img#strip"],"cad-comic.com":["div#content"],"twitter.com":[".permalink","div.content-main"],"blog.evernote.com":[".post"],"outlook.office.com":["[role='region']:nth-of-type(3)","#Item\\.MessagePartBody"],"outlook.live.com":["[role='region']:nth-of-type(3)","#Item\\.MessagePartBody"],"outlook-sdf.live.com":["[role='region']:nth-of-type(3)","#Item\\.MessagePartBody"],"inbox.google.com":["[aria-expanded=true][aria-multiselectable=false],[aria-expanded=true][aria-multiselectable=true] .scroll-list-item-open"],"nytimes.com":["#story"]},ha={"nytimes.com":["#story"]},ia={"blog.evernote.com":{container:"#page-wrap > section > article",include:"h2, .p-meta, .post-meta, .thumbnail, .art-content"},"kirei.biglobe.ne.jp":{container:"div#main",include:".recipeTitle, .recipeMain, #howTo"},"nomnompaleo.com":{container:"section article.text",include:"header, section"},"foodnetwork.com":{container:"#fn-w",include:".rcp-head, .tabnav, #recipe-lead, .w-inner, .body-text"}},ja=["xkcd.com"],ka={Baidu:{regex:/^https?:\/\/([^.\/]+\.)?baidu\.(com|cn)/i,content:"#container",searchBox:"input[name=wd]",allowedElements:"h3.t a[data-click], .f font[size='-1']",bannedSubelements:"span.g, .m, .c",titleTrim:function(a){var b=/(.+)_\u767E\u5EA6\u641C\u7D22/;return b.test(a)?b.exec(a)[1]:a}},Bing:{regex:/^https?:\/\/([^.\/]+\.)?bing\.com\/search/i,content:"#results_container, #b_results",searchBox:"input[name=q]",allowedElements:"div.sb_tlst a, div.sa_mc p, .b_algo h2 a, .b_algo .b_caption p"},Daum:{regex:/^https?:\/\/search\.daum\.net\/search/i,content:"#mArticle .inner_article",searchBox:"input[name=q]",allowedElements:".coll_cont ul .wrap_tit a, .coll_cont ul .f_eb.desc",titleTrim:function(a){var b=/(.+)\s\u2013/;return b.test(a)?b.exec(a)[1]:a}},Google:{regex:a.buildGoogleRegEx(),content:"#rso",searchBox:"input[name=q][type=hidden]",searchBoxAlt:"input[name=q]",allowedElements:"a.l, span.st",bannedSubelements:"span.f"},Naver:{regex:/^https?:\/\/search\.naver\.com\/search\.naver/i,content:"#content",searchBox:"input[name=query]",allowedElements:".type01 dt a, .type01 dd:not(.txt_inline):not(.txt_block):not(.review):not([style*='display:none'])",titleTrim:function(a){var b=/(.+)\s\u003A/;return b.test(a)?b.exec(a)[1]:a}},Yahoo:{regex:/^https?:\/\/([^.\/]+\.)*yahoo\.com\/s(earch|\?)/i,content:"#web",searchBox:"input[name=p]",allowedElements:".title, .aAbs",bannedSubelements:".fc-2nd, .TumblrV2, .Img, .Video, .sys_news_auto"},YahooJP:{regex:/^https?:\/\/([^.\/]+\.)*yahoo\.co\.jp\/s(earch|\?)/i,content:"#WS2m",searchBox:"input[name=p]",allowedElements:"#WS2m .hd h3 a, #WS2m .bd p",bannedSubelements:"#WS2m .bd p.dlink",titleTrim:function(a){var b=/\u300C(.+)\u300D/;return b.test(a)?b.exec(a)[1]:a}},Yandex:{regex:/^https?:\/\/([^.\/]+\.)?yandex\.(com|ru)\/search/,content:".serp-list",searchBox:"input[name=text]",allowedElements:".serp-item__title-link, .serp-item__text",bannedSubelements:".serp-item__date",titleTrim:function(a){var b=/(.+)\s+\u2014/;return b.test(a)?b.exec(a)[1]:a}}},la=[],ma=[],na=[],oa=!0,pa=!1,qa=!1,ra=null,sa=[],ta=c();return Browser.addMessageHandlers({getInfo:I}),"undefined"!=typeof SAFARI&&SAFARI&&(window.addEventListener("mouseup",r),Browser.addKeyboardHandlers({"65 + 91":r})),ea.getCustomFormatSiteName=K,ea.getCustomFormatReformattedData=M,ea.getThumbnail=S,ea.getDefaultArticle=m,ea.getNextPages=o,ea.getCanonicalUrl=W,ea.getSelection=s,ea.getSelectionFrame=F,ea.getPdfUrl=J,ea.getRecommendationText=E,ea.getSearchQuery=B,ea.getTitle=y,ea.getUrl=A,ea.getFavIconUrl=Y,ea.getSnippet=C,ea.isCustomFormat=L,ea.isOutlookMail=N,ea.isGmail=O,ea.isGmailThread=R,ea.isGoogleInboxThread=Q,ea.isSearchEngine=c,ea.getRealUrlFromOperaPdfViewerUrl=X,ea.lazyImagesLoad=Z,ea.__defineGetter__("documentIsFrameset",function(){return qa}),b&&(ea.findArticle=k,ea.findImage=d,ea.getCommonAncestor=e,ea.pickArticle=j,ea.refreshSearchEngine=function(){ta=c()},ea.__defineSetter__("findArticle",function(a){k=a})),ea});