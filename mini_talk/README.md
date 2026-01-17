*This project has been created as part of the 42 curriculum by masad.*

# mini_talk

## Description

**mini_talk** is a small data exchange program using UNIX signals. The project consists of a server and a client that communicate with each other using only `SIGUSR1` and `SIGUSR2` signals.

### Goal

The objective is to transmit a string of text from the client to the server, one bit at a time, using only UNIX signals as the communication mechanism. This project introduces concepts of:

- Inter-process communication (IPC)
- UNIX signal handling
- Bitwise operations
- Process identification (PID)

### How it works

1. The **server** starts first and displays its PID
2. The **client** takes the server's PID and a message as arguments
3. The client converts each character to binary and sends it bit by bit:
   - `SIGUSR1` represents bit `1`
   - `SIGUSR2` represents bit `0`
4. The server receives the signals, reconstructs each character, and prints the message

## Instructions

### Compilation

```bash
make        # Compiles both server and client
make clean  # Removes object files
make fclean # Removes object files and executables
make re     # Recompiles everything
```

### Execution

1. **Start the server:**
   ```bash
   ./server
   ```
   The server will display its PID (e.g., `Server PID: 12345`)

2. **Send a message from the client:**
   ```bash
   ./client <server_pid> "Your message here"
   ```
   Example:
   ```bash
   ./client 12345 "Hello, World!"
   ```

3. The message will be displayed on the server's terminal.

### Requirements

- Linux/macOS environment
- CC compiler
- Make

## Resources

### Documentation

- [signal(7) - Linux manual page](https://man7.org/linux/man-pages/man7/signal.7.html) - Overview of signals in Linux
- [sigaction(2) - Linux manual page](https://man7.org/linux/man-pages/man2/sigaction.2.html) - Examine and change a signal action
- [kill(2) - Linux manual page](https://man7.org/linux/man-pages/man2/kill.2.html) - Send signal to a process
- [Bitwise Operators in C](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/) - Understanding bit manipulation

### AI Usage

AI assistance (GitHub Copilot) was used in this project for:

- **Debugging**: Identifying and fixing issues with signal handling and bit manipulation logic
- **Code explanation**: Understanding the behavior of `sigaction`, `_POSIX_C_SOURCE`, and static variables
- **Optimization**: Improving signal transmission reliability with appropriate `usleep` timing

All code was reviewed and understood before implementation. The core logic and architecture were developed independently.
