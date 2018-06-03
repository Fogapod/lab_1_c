#define GRID_SIZE 20
#define GRID_EMPTY ' '
#define GRID_WOLF_MALE 'M'
#define GRID_WOLF_FEMALE 'F'
#define GRID_RABBIT 'R'
#define GRID_WATER '#'

#include <string>
#include <vector>
#include <ctime>
#include <map>
#include <ncurses.h>


struct MoveVector {
  int x;
  int y;

  MoveVector(): x(0), y(0) { }

  MoveVector(int _x, int _y): x(_x), y(_y) { }
};

MoveVector operator +(MoveVector u, MoveVector v) {
  MoveVector result;
  result.x = u.x + v.x;
  result.y = u.y + v.y;

  return result;
}

void operator +=(MoveVector &u, MoveVector v) {
  u.x += v.x;
  u.y += v.y;
}

enum Direction {
  n,
  e,
  s,
  w,
  ne,
  se,
  sw,
  nw,
  o
};

std::map<Direction, MoveVector> directions;

class Grid {
public:
  std::string grid;

  Grid()
  {
    for (int i = 0; i < GRID_SIZE + 2; i++) {
      grid += GRID_WATER;
    }
    grid += '\n';

    for (int i = 0; i < GRID_SIZE; i++) {
      grid += GRID_WATER;
      for (int j = 0; j < GRID_SIZE; j++) {
        grid += GRID_EMPTY;
      }
      grid += GRID_WATER;
      grid += '\n';
    }

    for (int i = 0; i < GRID_SIZE + 2; i++) {
      grid += GRID_WATER;
    }
    grid += '\0';
  }

  void initLife(int m_wolf_count, int f_wolf_count, int rabbit_count) {
    for (int i = m_wolf_count; i > 0; i--) {
      randomSpawnLife(GRID_WOLF_MALE);
    }
    for (int i = f_wolf_count; i > 0; i--) {
      randomSpawnLife(GRID_WOLF_FEMALE);
    }
    for (int i = rabbit_count; i > 0; i--) {
      randomSpawnLife(GRID_RABBIT);
    }
  }

  void randomSpawnLife(char c) {
    int index = rand() %grid.size();
    while (grid[index] != GRID_EMPTY) {
      index++;
      if (grid[index] == '\0') {
        index = 0;
      }
    }
    grid[index] = c;
  }

  char setChar(MoveVector location, char c) {
    return grid[location.y *  (GRID_SIZE + 2) + location.x] = c;  
  }

  char getChar(MoveVector location) {
    return grid[location.y * (GRID_SIZE + 2) + location.x];
  }

  std::map<Direction, char> findDirectSurroundings(MoveVector pos) {
    std::map<Direction, char> surroundings;
    for (int i = 0; i < 9; i++) {
      surroundings[(Direction)i] = getChar(pos + directions[(Direction)i]);
    }
    return surroundings;
  }

  template <class T>
  void registerLife(char ch, std::vector<T> &lifeVect, T (*make_f)(MoveVector)) {
    for (int y = 0; y <= GRID_SIZE + 2; y++) {
      for (int x = 0; x <= GRID_SIZE + 2; x++) {
        if (getChar(MoveVector(x, y)) == ch)
          lifeVect.push_back((*make_f)(MoveVector(x, y)));
      }
    }
  }

  template <class T>
  T newLife(T life) {
    setChar(life.currentPos, life.ch);
    return life;
  }

  template <class T>
  void killLife(std::vector<T> &lifeVect, int i) { 
    if (getChar(lifeVect[i].currentPos) == lifeVect[i].ch)
      setChar(lifeVect[i].currentPos, GRID_EMPTY);
    lifeVect.erase(lifeVect.begin() + i);
  }
};


struct Rabbit {
  MoveVector currentPos;
  MoveVector newPos;
  char ch;

  std::map<Direction, char> surroundings;

  Rabbit(MoveVector startpos) {
    currentPos = startpos;
    newPos = startpos;

    ch = GRID_RABBIT;
  }
};

struct MaleWolf {
  MoveVector currentPos;
  MoveVector newPos;
  int health;
  char ch;

  std::map<Direction, char> surroundings;

  MaleWolf(MoveVector startpos)
    : currentPos(startpos)
    , newPos(startpos)
    , health(10)
    , ch(GRID_WOLF_MALE)
    { }
};

struct FemaleWolf {
  MoveVector currentPos;
  MoveVector newPos;
  int health;
  char ch;
  bool breeded = false;

  std::map<Direction, char> surroundings;

  FemaleWolf(MoveVector startpos)
    : currentPos(startpos)
    , newPos(startpos)
    , health(10)
    , ch(GRID_WOLF_FEMALE)
    { }
};

Rabbit makeRabbit(MoveVector pos) {
  return Rabbit(pos);
}

MaleWolf makeMaleWolf(MoveVector pos) {
  return MaleWolf(pos);
}

FemaleWolf makeFemaleWolf(MoveVector pos) {
  return FemaleWolf(pos);
}


template <class T>
void move(Grid &g, T &b, Direction d) {
  MoveVector newPos = b.currentPos + directions[d];

  g.grid[newPos.y * (GRID_SIZE + 2) + newPos.x] = b.ch;
  g.grid[b.currentPos.y * (GRID_SIZE + 2) + b.currentPos.x] = GRID_EMPTY;
  b.currentPos = newPos;
}

int findCharDirection(std::map<Direction, char> surroundings, char c) {
  int d = rand() % directions.size();
  if (d == 8 && c == GRID_EMPTY) return d;

  for (int i = 0; i <= (int)directions.size();  i++) {
    if (surroundings[(Direction)d] == c)
        return d;
    d = (d >= (int)directions.size())? 0: d + 1;
  }
  return -1;
}

Grid g;

std::vector<Rabbit> rabbits;
std::vector<MaleWolf> maleWolfes;
std::vector<FemaleWolf> femaleWolfes;

void initGrid() {
  g = Grid();

  g.initLife(3, 3, 8);
  g.registerLife(GRID_RABBIT, rabbits, makeRabbit);
  g.registerLife(GRID_WOLF_MALE, maleWolfes, makeMaleWolf);
  g.registerLife(GRID_WOLF_FEMALE, femaleWolfes, makeFemaleWolf);
}


void cleanupGrid() {
  rabbits.clear();
  maleWolfes.clear();
  femaleWolfes.clear();
}


int main() {
  srand(time(0));

  directions[o] = MoveVector(0, 0);
  directions[n] = MoveVector(0, -1);
  directions[e] = MoveVector(1, 0);
  directions[s] = MoveVector(0, 1);
  directions[w] = MoveVector(-1, 0);
  directions[ne] = MoveVector(1, -1);
  directions[se] = MoveVector(1, 1);
  directions[sw] = MoveVector(-1, 1);
  directions[nw] = MoveVector(-1, -1);

  initGrid();

  initscr();
  raw();
  keypad(stdscr, true);
  noecho();
  timeout(0);
  curs_set(0);

  int c;
  bool paused = false;

  while ((c = getch()) != 'q') {
    napms(40);

    if (c == ' ') {
      paused = !paused;
    }

    if (c == 'r') {
      cleanupGrid();
      initGrid();
    }

    if (paused) {
      continue;
    }

    mvprintw(0, 0, g.grid.c_str());

    // rabbit
    for (size_t i = 0; i < rabbits.size(); i++) {
      Rabbit *r = &rabbits[i];
      if (g.getChar(r->currentPos) != GRID_RABBIT) {
        g.killLife(rabbits, i);
        continue;
      }
      int d;

      r->surroundings = g.findDirectSurroundings(r->currentPos);
      if ((random() % 10) < 2) {
        d = findCharDirection(g.findDirectSurroundings(r->currentPos), GRID_EMPTY);
        if (d != -1) {
          rabbits.push_back(g.newLife(Rabbit(r->currentPos + directions[(Direction)d])));
          r->surroundings[(Direction)d] = GRID_RABBIT;
        }
      }

      // check surroundings to find move spot
      if ((d = findCharDirection(r->surroundings, GRID_EMPTY)) != -1) {
          move(g, *r, (Direction)d);
      }
    }

    // male wolf
    for (size_t i = 0; i < maleWolfes.size(); i++) {
      MaleWolf *mw = &maleWolfes[i];
      mw->surroundings = g.findDirectSurroundings(mw->currentPos);
      int d;

      // check surroundings for rabbits
      if ((d = findCharDirection(mw->surroundings, GRID_RABBIT)) != -1) {
          move(g, *mw, (Direction)d);
          mw->health += 10;
      }

      // check surroundings for females
      else if ((d = findCharDirection(mw->surroundings, GRID_WOLF_FEMALE)) != -1) {
        d = findCharDirection(g.findDirectSurroundings(mw->currentPos), GRID_EMPTY);

        // check surroundings for empty space to put child
        if (d != -1) {
          if (rand() % 2) {
            maleWolfes.push_back(g.newLife(MaleWolf(mw->currentPos + directions[(Direction)d])));
          }
          else {
            femaleWolfes.push_back(g.newLife(FemaleWolf(mw->currentPos + directions[(Direction)d])));
          }
          mw->health -= 5;
        }
      }

      // check surroundings to find move spot
      else if ((d = findCharDirection(mw->surroundings, GRID_EMPTY)) != -1) {
        move(g, *mw, (Direction)d);
      }

      mw->health -= 1;
      if (mw->health <= 0) {
         g.killLife(maleWolfes, i);
      }
    }

    // female wolf
    for (size_t i = 0; i < femaleWolfes.size(); i++) {
      FemaleWolf *fw = &femaleWolfes[i];
      if (fw->breeded) {
        fw->breeded = false;
        continue;
      }
      fw->surroundings = g.findDirectSurroundings(fw->currentPos);
      int d;

      // check surroundings for rabbits
      if ((d = findCharDirection(fw->surroundings, GRID_RABBIT)) != -1) {
          move(g, *fw, (Direction)d);
          fw->health += 10;
      }

      // check surroundings to find move spot
      else if ((d = findCharDirection(fw->surroundings, GRID_EMPTY)) != -1) {
        move(g, *fw, (Direction)d);
      }

      fw->health -= 1;
      if (fw->health <= 0) {
        g.killLife(femaleWolfes, i);
      }
    }
  }
  refresh();
  endwin();
}