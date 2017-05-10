-module(shop2).
-author("admin").

%% API
-export([total/1]).
-import(mylists, [map/2, sum/1]).

total(L) ->
    sum(map(fun({What, N}) -> shop:cost(What) * N end, L)).