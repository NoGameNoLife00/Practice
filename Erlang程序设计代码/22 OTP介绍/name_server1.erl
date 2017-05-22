-module(name_server1).
-import(server3, [rpc/2]).
%% API
-export([add/2, find/1, init/0, handle/2]).

%% 客户端方法
add(Name, Place)    -> rpc(name_server, {add, Name, Place}).
find(Name)          -> rpc(name_server, {find, Name}).

%% 回调方法
init() -> dict:new().
handle({add, Name, Place}, Dict)    -> {ok, dict:store(Name, Place, Dict)};
handle({find, Name}, Dict)          -> {dict:find(Name, Dict), Dict}.
