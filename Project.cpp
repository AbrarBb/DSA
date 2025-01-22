#include <windows.h>

#include <algorithm>

#include <ctime>

#include <exception>

#include <functional>

#include <iostream>

#include <map>

#include <queue>

#include <random>

#include <vector>

using namespace std;

mt19937 RAND_GENERATOR;



struct Cell {

  int x;

  int y;

};



class Queue {

  struct Node {

    Cell value;

    Node *next;

  };



Node *first = nullptr, *last = nullptr;

  int size = 0;

  bool empty = true;



 public:

  void push(Cell);

  Cell pop();

  Cell front();

  bool isEmpty();

};



void Queue::push(Cell cell) {

  Node *node = new Node;

  node->value = cell;

  if (last == nullptr)

    first = node;

  else

    last->next = node;

  last = node;

  size++;

  empty = false;

}



Cell Queue::pop() {

  if (empty) throw "Queue is empty!";

  Node *oldFirst = first;

  Cell oldValue = first->value;

  first = oldFirst->next;

  delete oldFirst;

  size--;

  if (size == 0) {

    empty = true;

    last = nullptr;

  }

  return oldValue;

}



Cell Queue::front() {

  if (empty) throw "Queue is empty!";

  return first->value;

}



bool Queue::isEmpty() { return empty; }



class GameBoard {

  int height;

  int width;

  bool gameover = false;

  vector<string> board;

  map<int, function<bool()>> handlers;



  int readinput();

  void print();

  inline void clear();

  int shortestPath(Cell, Cell);



 public:

  static const char PLAYER = 'O';

  static const char EXIT = 'X';

  static const char BLANK = ' ';

  static const char WALL = '#';



  GameBoard(int, int);



  void setInputHandler(int, function<bool()>);

  void set(int, int, char);

  char get(int, int);

  void resize(int, int);

  int getHeight();

  int getWidth();

  bool isGameOver();

  void generateMaze(int, int);

  void gameOver(bool);

  void init(int &, int &, int);

};



GameBoard::GameBoard(int w, int h)

    : height(h), width(w), board(h, string(w, WALL)) {}



void GameBoard::resize(int w, int h) {

  width = w;

  height = h;

  board.resize(h);

  for (auto row: board)

    row = string(w, WALL);

}



void GameBoard::set(int x, int y, char c) { board[y][x] = c; }

char GameBoard::get(int x, int y) { return board[y][x]; }



int GameBoard::getHeight() { return height; }



int GameBoard::getWidth() { return width; }



bool GameBoard::isGameOver() { return gameover; }



void GameBoard::print() {

  for (int i = 0; i < height; i++) cout << board[i] << "\n";

}



void GameBoard::gameOver(bool st = true) { gameover = st; }



inline void GameBoard::clear() { system("cls"); }



int GameBoard::readinput() {

  const int keys[] = {VK_UP, VK_RIGHT, VK_DOWN, VK_LEFT, VK_ESCAPE};

  int state = 0, keyIndex = 0;

  int n = sizeof(keys) / sizeof(int);

  do {

    state = GetAsyncKeyState(keys[keyIndex++]);

    if (keyIndex == n) keyIndex = 0;

  } while (state >= 0);

  keyIndex = (keyIndex - 1 + n) % n;

  while (GetAsyncKeyState(keys[keyIndex]) < 0)

    ;

  return keys[keyIndex];

}



void GameBoard::setInputHandler(int key, function<bool()> handler) {

  handlers[key] = handler;

}



void GameBoard::generateMaze(int x = 1, int y = 1) {

  vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  shuffle(dir.begin(), dir.end(), RAND_GENERATOR);

  for (int i = 0; i < dir.size(); i++) {

    int dX = dir[i].first;

    int dY = dir[i].second;

    int nX = x + dX * 2;

    int nY = y + dY * 2;

    if (nX > 0 and nX < width and nY > 0 and nY < height and

        board[nY][nX] == WALL) {

      board[y + dY][x + dX] = BLANK;

      board[nY][nX] = BLANK;

      generateMaze(nX, nY);

    }

  }

}



int GameBoard::shortestPath(Cell src, Cell dest) {  // BFS

  const int dx[] = {0, 1, 0, -1};

  const int dy[] = {-1, 0, 1, 0};

  vector<vector<int>> distance(height, vector<int>(width));

  vector<vector<bool>> visited(height, vector<bool>(width, false));

  Queue q;

  q.push(src);

  distance[src.y][src.x] = 0;

  visited[src.y][src.x] = true;

  while (!q.isEmpty()) {

    auto current = q.pop();

    for (int i = 0; i < 4; i++) {

      Cell nxt = {current.x + dx[i], current.y + dy[i]};

      if (0 <= nxt.x and nxt.x < width and 0 <= nxt.y and nxt.y < height and

          board[nxt.y][nxt.x] != GameBoard::WALL and !visited[nxt.y][nxt.x]) {

        q.push(nxt);

        distance[nxt.y][nxt.x] = distance[current.y][current.x] + 1;

        visited[nxt.y][nxt.x] = true;

      }

    }

  }

  return distance[dest.y][dest.x];

}



void GameBoard::init(int &x, int &y, int delay = 0) {

  generateMaze();



  int destX = width - 2, destY = height - 2; // destination coordinates

  set(x, y, GameBoard::PLAYER);             // place player

  set(destX, destY, GameBoard::EXIT);       // set destination/exit



  int moves = shortestPath({x, y}, {destX, destY});

  while (!gameover) {

    clear();

    cout << "Moves Left: " << moves << "\n" << endl;

    print();

    Sleep(delay);

    if (moves == 0) {

      if (x != destX || y != destY) {

        cout << "Game Over! You ran out of moves." << endl;

      } else {

        cout << "Congratulations! You won!" << endl;

      }

      cout << "Press any key to exit..." << endl;

      return;

    }

    int key = readinput();

    if (handlers.find(key) == handlers.end()) continue;

    if (handlers[key]()) moves--;

  }

  fill(board.begin(), board.end(), string(width, GameBoard::WALL));

}



void setHandlers(GameBoard &gb, Cell &p) {

  gb.setInputHandler(VK_UP, [&p, &gb]() {

    if (p.y - 1 < 1 or gb.get(p.x, p.y - 1) == GameBoard::WALL) return false;

    gb.set(p.x, p.y, GameBoard::BLANK);

    gb.set(p.x, --p.y, GameBoard::PLAYER);

  });



  gb.setInputHandler(VK_DOWN, [&p, &gb]() {

    if (p.y + 1 >= gb.getHeight() or gb.get(p.x, p.y + 1) == GameBoard::WALL)

      return false;

    gb.set(p.x, p.y, GameBoard::BLANK);

    gb.set(p.x, ++p.y, GameBoard::PLAYER);

  });



  gb.setInputHandler(VK_LEFT, [&p, &gb]() {

    if (p.x - 1 < 1 or gb.get(p.x - 1, p.y) == GameBoard::WALL) return false;

    gb.set(p.x, p.y, GameBoard::BLANK);

    gb.set(--p.x, p.y, GameBoard::PLAYER);

  });



  gb.setInputHandler(VK_RIGHT, [&p, &gb]() {

    if (p.x + 1 >= gb.getWidth() or gb.get(p.x + 1, p.y) == GameBoard::WALL)

      return false;

    gb.set(p.x, p.y, GameBoard::BLANK);

    gb.set(++p.x, p.y, GameBoard::PLAYER);

  });



  gb.setInputHandler(VK_ESCAPE, [&gb]() {

    if (gb.isGameOver()) return false;

    gb.gameOver();

    return true;

  });

}



int main() {

  RAND_GENERATOR.seed(time(nullptr));

  int W = 25, H = 15;

  GameBoard board(W, H);

  Cell playerPos = {1, 1};

  setHandlers(board, playerPos);

  board.init(playerPos.x, playerPos.y);

  system("pause > 0");

}
