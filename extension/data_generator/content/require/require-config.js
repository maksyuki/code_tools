/*! Copyright 2009-2017 Evernote Corporation. All rights reserved. */

function finishLoadingScript(request,sender,sendResponse){request.moduleName&&EXTENSION_FILE_REGEX.test(request.href)&&(eval(request.responseText),require.s.contexts[REQUIRE_CONTEXT_NAME].completeLoad(request.moduleName)),sendResponse&&"function"==typeof sendResponse&&sendResponse()}function setupLoadFunction(){SAFARI?(Browser.addMessageHandlers({content_textResource:finishLoadingScript}),require.s.contexts[REQUIRE_CONTEXT_NAME].load=function(a,b){Browser.sendToExtension({name:"main_getTextResource",href:b,moduleName:a})}):require.s.contexts[REQUIRE_CONTEXT_NAME].load=function(a,b){var c=new XMLHttpRequest;c.open("GET",b),c.href=b,c.moduleName=a,c.onreadystatechange=function(){4===this.readyState&&200===this.status&&finishLoadingScript(this)},c.send()}}var REQUIRE_CONTEXT_NAME="clipper",EXTENSION_FILE_REGEX=new RegExp("^"+Browser.extension.getURL("")),reqC=require.config({baseUrl:Browser.extension.getURL("content"),callback:setupLoadFunction,context:REQUIRE_CONTEXT_NAME,paths:{checkSimSearch:"require/checkSimSearch",CustomTooltipEligibility:"tooltips/CustomTooltipEligibility",domReady:"../third_party/require/domReady",GlobalUtils:"../js/GlobalUtils",isTest:"require/isTest",pageVisible:"require/pageVisible",topFrame:"require/topFrame"},skipDataMain:!0,waitSeconds:0});