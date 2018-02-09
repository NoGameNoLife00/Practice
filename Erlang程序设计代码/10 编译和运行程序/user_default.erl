-module(user_default).
-compile(export_all).
%% API
hello() ->
    "hello joe how are you?".

away(Time) ->
    io:format("joe is away and will be back in ~w minutes~n", [Time]).
