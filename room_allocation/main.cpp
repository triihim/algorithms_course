#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Room {
  int number;
  int takenUntil;
  bool operator>(const Room& other) const {
    return takenUntil > other.takenUntil;
  }
};

struct Customer {
  int index;
  int arrival;
  int departure;
  int givenRoom;
  bool operator>(const Customer& other) const {
    return index > other.index;
  }
  bool operator<(const Customer& other) const {
    return index < other.index;
  }
};

struct CustomerComparator {
  bool operator()(const Customer& c1, const Customer& c2) const {
    return c1.arrival < c2.arrival;
  }
};

int main() {
  int n = 0; std::cin >> n;
  auto customerSchedule = std::vector<Customer>();
  for(int i = 0; i < n; i++) {
    int arrival, departure; std::cin >> arrival >> departure;
    customerSchedule.push_back({i, arrival, departure, 0});
  }

  CustomerComparator cmp;
  std::sort(customerSchedule.begin(), customerSchedule.end(), cmp);

  auto availableRooms = std::priority_queue<int, std::vector<int>, std::greater<int>>();
  auto occupiedRooms = std::priority_queue<Room, std::vector<Room>, std::greater<Room>>();
  int usedRoomCount = 0;
  for(auto& cs : customerSchedule) {
    while(!occupiedRooms.empty() && occupiedRooms.top().takenUntil < cs.arrival) {
      int room = occupiedRooms.top().number;
      availableRooms.push(room);
      occupiedRooms.pop();
    }

    if(!availableRooms.empty()) {
      cs.givenRoom = availableRooms.top();
      availableRooms.pop();
    } else {
      cs.givenRoom = ++usedRoomCount;
    }
    occupiedRooms.push({cs.givenRoom, cs.departure});
  }

  std::cout << usedRoomCount << std::endl;
  std::sort(customerSchedule.begin(), customerSchedule.end());

  for(const auto& cs : customerSchedule) {
    std::cout << cs.givenRoom << " ";
  }
  std::cout << std::endl;


  return 0;
}