#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

namespace {

struct Shape {
  virtual bool Contains(double x, double y) const = 0;
};

struct Rect : public Shape {
  bool Contains(double x, double y) const override {
    return x1 < x && x < x2 && y2 < y && y < y1;
  }

  double x1, y1, x2, y2;
};

struct Circle : public Shape {
  bool Contains(double xx, double yy) const override {
    return sqrt(pow(x - xx, 2) + pow(y - yy, 2)) < r;
  }

  double x, y, r;
};

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<unique_ptr<Shape>> shapes;
  char shape;
  cin >> shape;
  while (shape != '*') {
    if (shape == 'r') {
      Rect* r = new Rect;
      cin >> r->x1 >> r->y1 >> r->x2 >> r->y2;
      shapes.emplace_back(r);
    } else {
      Circle* c = new Circle;
      cin >> c->x >> c->y >> c->r;
      shapes.emplace_back(c);
    }
    cin >> shape;
  }
  double x, y;
  cin >> x >> y;
  size_t pt = 0;
  while (x != 9999.9 || y != 9999.9) {
    pt++;
    bool found = false;
    for (size_t i = 0; i < shapes.size(); i++) {
      if (shapes[i]->Contains(x, y)) {
        cout << "Point " << pt << " is contained in figure " << (i + 1) << '\n';
        found = true;
      }
    }
    if (!found) {
      cout << "Point " << pt << " is not contained in any figure\n";
    }
    cin >> x >> y;
  }
  return 0;
}
