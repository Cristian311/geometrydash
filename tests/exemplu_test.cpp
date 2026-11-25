// Main ships no test framework on purpose: plain assert / static_assert only.
// Full framework examples live on tests/gtest and tests/Boost-ext-ut branches.

// assert() disappears when NDEBUG is defined (Release, RelWithDebInfo): the
// binary would exit 0 having checked nothing, and CI would call that a pass.
// Keep the checks on in every build type.
#undef NDEBUG
#include <cassert>
#include <stdexcept>

#include "Example.h"      // the library under test; include/ comes from oop
#include "Obstacle.h"
#include "Player.h"

static_assert(Example::limit > 0, "the invariant below assumes a positive limit");

// checked through the public interface only: the helper behind the invariant is
// file-local in src/Example.cpp and cannot even be named here
int main() {
    Example e;
    assert(e.value() == 0);

    e.add(7);
    assert(e.value() == 7);
    e.add(-7);
    assert(e.value() == 0);

    bool threw = false;
    try {
        e.add(-1);
    } catch (const std::invalid_argument&) {
        threw = true;
    }
    assert(threw && "add() must refuse to go below 0");
    assert(e.value() == 0 && "a failed call leaves the object untouched");

    threw = false;
    try {
        e.add(Example::limit + 1);
    } catch (const std::invalid_argument&) {
        threw = true;
    }
    assert(threw && "add() must refuse to go above limit");

    threw = false;
    try {
        Example broken{Example::limit + 1};
        (void) broken;
    } catch (const std::invalid_argument&) {
        threw = true;
    }
    assert(threw && "the constructor must not hand out a broken object either");

    Player player;
    player.setPosition({40.f, 36.f});
    player.jump();
    player.update(0.1f, 100.f);
    assert(player.getShape().getPosition().y < 36.f);
    player.update(1.f, 100.f);
    assert(player.getShape().getPosition().y == 36.f);

    Obstacle obstacle({50.f, 40.f}, 60.f, 60.f);
    player.setPosition({40.f, 40.f});
    assert(player.collidesWith(obstacle));
    obstacle.getShape().setPosition({500.f, 40.f});
    assert(!player.collidesWith(obstacle));

    Obstacle copiedObstacle(obstacle);
    Obstacle assignedObstacle({0.f, 0.f}, 10.f, 10.f);
    assignedObstacle = copiedObstacle;
    assert(assignedObstacle.getShape().getPosition().x == 500.f);

    return 0;
}
