MUTual EXclusion

взять/отпустить
захватить/отпустить
заблокировать/разблокировать
lock/unlock
acquire/release

Mutex:
    
    T1       std::mutex m1;       T2        std::mutex m2;        T3
    │               │             │                 │             │
┌─m1.lock()─────────┼──────┐      │                 │             │
│   │               │      │┌──m1.lock()──┐         │             │
│   │               │      ││     .       │┌────────┼──────────m2.lock()──┐
└m1.unlock()────────┼──────┘│     .       ││        │             │       │
    │       ┌───────┼───────┘     .       ││        │             │       │
    │       │       │             │       ││        │             │       │
    │       └───────┼─────────m1.unlock()─┘│        │             │       │
    │               │       ┌──m2.lock()──┐│        │             │       │
    │               │       │     .       │└────────┼─────────m2.unlock()─┘
    │               │       │     .       └─────────┼──────┐      │
    │               │       │     │                 │      │      │
    │               │       └─m2.unlock()───────────┼──────┘      │
    │               │             │                 │             │
