-module(test2).
-author("admin").

%% API
-export([f1/0]).

f1() ->
    tuple_size(list_to_tuple({a, b, c})).