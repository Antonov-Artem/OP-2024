struct CPU {
  char* brand;
  char* model;
  int cores;
  int threads;
  double base_clock;
  double boost_clock;
  double cache;
};

struct GPU {
  char* brand;
  char* model;
  double memory;
  double core_clock;
  double boost_clock;
  double power_consumption;
};

struct RAM {
  char* type;
  int modules;
  double capacity;
  double frequency;
};

struct ROM {
  char* type;
  int capacity;
  double read_speed;
  double write_speed;
};

struct Computer {
  char* manufacturer;
  char* model;
  char* os;
  double weight;
  double price;
  bool is_laptop;

  struct CPU cpu;
  struct GPU* gpus;
  struct RAM* rams;
  struct ROM* roms;
};
