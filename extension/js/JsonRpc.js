/*! Copyright 2009-2017 Evernote Corporation. All rights reserved. */

function JsonRpc(a,b){"use strict";function c(){k=!0;for(var a=0;a<j.length;a++)j[a]()}function d(a,b){if(k&&b)return void b();b&&j.push(b),c||g(a);var c=!0}function e(a,c){if(!a)throw"Missing shardId!";m||(m=a),d(b+"/shard/"+m+"/json",c)}function f(a,c,e){if(!a)throw new Error("Missing shardId!");if(void 0===c)throw new Error("Missing slot!");m||(m=a),d(b+"/shard/"+m+"/u/"+c+"/json",e)}function g(b){l=new JSONRpcClient(a,b),c()}function h(a){log.error("JsonRpc Exception: "+(a.trace||a.stack||a))}function i(a){return a||(a=[]),{list:a,javaClass:"java.util.ArrayList"}}a||log.warn("No methodList provided to JsonRpc object. Consider providing this for performance reasons.");var j=[],k=!1,l=null,m=null;JSONRpcClient.toplevel_ex_handler=h,this.initWithUrl=d,this.initWithShardId=e,this.initWithSlot=f,this.listify=i,this.__defineGetter__("client",function(){return l}),this.__defineGetter__("shardId",function(){return m}),Object.preventExtensions(this)}