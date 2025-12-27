# Chess

Simple terminal chess game written in C++.

## Build

```
g++ -std=c++17 -O2 -o chess main.cpp game/game.cpp pieces/pieces.cpp
```

## Run

```
./chess
```

## Notes

- Special moves (castling, en passant, promotion) are not implemented yet.
- Draw detection is not implemented yet.
