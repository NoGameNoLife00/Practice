-module(lib_misc).
-author("admin").

%% API
-export([for/3, qsort/1, pythag/1, perms/1,
    odds_and_evens1/1, odds_and_evens2/1,
    sqrt/1, sum/1, sleep/1, flush_buffer/0,
    priority_receive/0, on_exit/2]).

for(Max, Max, F) -> [F(Max)];
for(I, Max, F) -> [F(I)|for(I+1,Max,F)].

qsort([]) -> [];
qsort([Pivot|T]) ->
    qsort([X || X <- T, X < Pivot])
    ++ [Pivot] ++
    qsort([X || X <- T, X >= Pivot]).

pythag(N) ->
    [{A,B,C} ||
        A <- lists:seq(1,N),
        B <- lists:seq(1,N),
        C <- lists:seq(1,N),
        A+B+C =< N,
        A*A+B*B=:=C*C
    ].

perms([]) -> [[]];
perms(L) -> [[H|T] || H <- L, T <- perms(L--[H])].

odds_and_evens1(L) ->
    Odds = [X || X <- L, (X rem 2) =:= 1],
    Evens = [X || X <- L, (X rem 2) =:= 0],
    {Odds, Evens}.

odds_and_evens2(L) ->
    odds_and_evens_acc(L, [], []).

odds_and_evens_acc([H|T], Odds, Evens) ->
    case (H rem 2) of
        1 -> odds_and_evens_acc(T, [H|Odds], Evens);
        0 -> odds_and_evens_acc(T, Odds, [H|Evens])
    end;
odds_and_evens_acc([], Odds, Evens) ->
    {lists:reverse(Odds), lists:reverse(Evens)}.


sqrt(X) when X < 0 ->
    error({squareRootNegativeArgument,X});
sqrt(X) ->
    math:sqrt(X).

sum(L) -> sum(L,0).

sum([], N) -> N;
sum([H|T], N) -> sum(T, H+N).

sleep(T) ->
    receive
        after T ->
            true
    end.

flush_buffer() ->
    receive
        _Any ->
            flush_buffer()
    after 0 ->
        receive
            Any ->
                Any
        end
    end.

priority_receive() ->
    receive
        {alarm, X} ->
            {alarm, X}
    after 0 ->
        receive
            Any ->
                Any
        end
    end.

on_exit(Pid, Fun) ->
    spawn(fun() ->
            Ref = monitor(process, Pid),
            receive
                {'DOWN', Ref, process, Pid, Why} ->
                    Fun(Why)
            end
          end).