-module(hello).

%% API
-export([start/0]).

start() ->
  io:format("Hello world~n").
