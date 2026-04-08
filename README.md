# 🍝 Philosophers

A concurrency and synchronization project developed as part of the **42 School curriculum**, based on the famous **Dining Philosophers Problem**.
This project introduces the fundamentals of **multithreading**, **process management**, and **resource sharing** in C.

---

## 📖 Overview

**Philosophers** is a simulation of a classic computer science problem where multiple entities compete for limited shared resources. The goal is to design a system that allows all participants to function correctly without causing **deadlocks**, **race conditions**, or **starvation**.

The project focuses on:

* Concurrent programming using threads and/or processes
* Synchronization of shared resources
* Preventing deadlocks and starvation
* Writing efficient and safe multithreaded code

The challenge is to ensure that all philosophers can eat, sleep, and think properly while sharing a limited number of forks.

---

## 🧠 Learning Objectives

By completing this project, you will gain experience with:

* Multithreading (`pthread`)
* Process management (bonus part)
* Mutexes and semaphores
* Race condition prevention
* Deadlock avoidance strategies
* Time management and scheduling
* Writing safe concurrent code

---

## 📂 Project Structure

```id="ph1a2b"
philosophers/
├── philo/          # Mandatory part (threads & mutexes)
├── philo_bonus/    # Bonus part (processes & semaphores)
├── include/        # Header files
├── libft/          # Custom C library dependency
├── Makefile        # Build system
└── README.md
```

Typical components include:

* Thread or process creation logic
* Fork/resource management
* Time tracking and monitoring
* Logging system for philosopher actions

---

## 🍽️ The Dining Philosophers Problem

The problem is defined as follows:

* A number of philosophers sit around a table
* Each philosopher alternates between:

  * **Eating**
  * **Sleeping**
  * **Thinking**
* There is one fork between each pair of philosophers
* A philosopher needs **two forks** to eat
* If a philosopher does not eat in time → they **die**

The challenge is to coordinate access to forks so that:

* No two philosophers use the same fork simultaneously
* No philosopher starves
* The system does not enter a deadlock state

---

## ⚙️ Program Arguments

```bash id="phargs1"
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Parameters

* `number_of_philosophers` → total philosophers (and forks)
* `time_to_die` → time before starvation (ms)
* `time_to_eat` → duration of eating (ms)
* `time_to_sleep` → duration of sleeping (ms)
* `number_of_times_each_philosopher_must_eat` → optional stop condition

---

## 🧩 How It Works

A typical implementation follows this logic:

### 1. Initialization

* Create philosophers (threads or processes)
* Initialize forks (mutexes or semaphores)

---

### 2. Simulation Loop

Each philosopher repeats:

1. Take forks
2. Eat
3. Release forks
4. Sleep
5. Think

---

### 3. Synchronization

* Use **mutexes** to protect forks
* Prevent multiple philosophers from accessing the same fork
* Avoid circular waiting (deadlock)

---

### 4. Monitoring

* Track last meal time
* Detect if a philosopher dies
* Stop simulation when conditions are met

---

## 🧵 Mandatory vs Bonus

### 🔹 Mandatory Part

* Uses **threads (`pthread`)**
* Uses **mutexes** for synchronization
* Shared memory between threads

---

### 🌟 Bonus Part

* Uses **processes (`fork`)**
* Uses **semaphores** instead of mutexes
* Handles multiple processes safely

---

## 📤 Output Format

The program logs actions in the following format:

```text id="phlog1"
timestamp philosopher_id has taken a fork
timestamp philosopher_id is eating
timestamp philosopher_id is sleeping
timestamp philosopher_id is thinking
timestamp philosopher_id died
```

Each action must be printed in real-time without mixing outputs between threads.

---

## ⚙️ Compilation & Usage

To build the project:

```bash id="phbuild1"
make
```

### Cleaning

```bash id="phclean1"
make clean      # Remove object files
make fclean     # Remove object files + binaries
make re         # Rebuild everything
```

---

## 🚀 How to Use

```bash id="phrun1"
./philo 5 800 200 200
```

Example with meal limit:

```bash id="phrun2"
./philo 5 800 200 200 7
```

---

## 📌 Constraints

* Limited allowed functions (e.g., `pthread`, `malloc`, `write`, etc.)
* No data races allowed
* Output must not be corrupted or mixed
* Must handle edge cases (1 philosopher, large inputs, etc.)
* Must avoid:

  * Deadlocks
  * Starvation
  * Race conditions

---

## 🎯 Key Concepts Covered

| Category           | Topics              |
| ------------------ | ------------------- |
| Concurrency        | Threads, processes  |
| Synchronization    | Mutexes, semaphores |
| Resource Sharing   | Fork allocation     |
| Algorithms         | Deadlock avoidance  |
| System Programming | Timing, scheduling  |

---

## 🚀 Purpose of the Project

The **Philosophers** project is designed to:

* Introduce concurrent programming concepts
* Teach safe access to shared resources
* Develop debugging skills for timing-related bugs
* Prepare for real-world multithreaded applications

---

## ⚠️ Notes

* Timing precision is critical for correctness
* Small delays can introduce subtle bugs
* Debugging concurrency issues can be challenging
* Proper synchronization design is essential

---

## 🤝 Contributing

Contributions and improvements are welcome!

1. Fork the repository
2. Create a feature branch
3. Submit a pull request

---

## 📄 License

This project is for educational purposes.
Refer to the repository for licensing details (if provided).

---

## 📚 Resources

To deepen your understanding:

* Dining Philosophers problem (Edsger Dijkstra)
* Multithreading in C (`pthread`)
* Synchronization primitives (mutexes, semaphores)
* Deadlock and race condition theory

---
