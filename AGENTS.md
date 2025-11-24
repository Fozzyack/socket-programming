# AGENTS.md - Socket Programming Practice Repository

This document provides essential information for AI agents working with this C socket programming codebase.

## Project Overview

A C project for learning and practicing socket programming concepts. The codebase is structured for network programming development with clean build system and formatting configuration.

## Essential Commands

### Build Commands
- `make` - Build the main executable (`bin/a.out`)
- `make clean` - Remove all build artifacts from `bin/` and `obj/` directories
- `gcc -c src/file.c -o obj/file.o -Iinclude` - Manual compilation of individual source files
- `gcc -o bin/program obj/*.o -Iinclude` - Manual linking

### Run Commands
- `./bin/a.out` - Execute the compiled program

### Code Formatting
- `clang-format -i src/*.c include/*.h` - Format all C source and header files

## Code Organization

### Directory Structure
```
├── include/          # Header files
│   └── common.h      # Common definitions and error codes
├── src/              # Source files
│   └── main.c        # Entry point with socket server implementation
├── bin/              # Compiled executables (created by build)
├── obj/              # Object files (created by build)
├── Makefile          # Build configuration
├── .clang-format     # Code formatting rules (LLVM-based)
└── .gitignore        # Git ignore rules
```

### Key Files
- **src/main.c**: Contains `start_server()` function implementing basic TCP server with socket, bind, listen, and accept operations
- **include/common.h**: Defines standard error codes (`STATUS_SUCCESS`, `STATUS_ERROR`)

## Code Style and Conventions

### Formatting Rules (from .clang-format)
- **Indentation**: 4 spaces (no tabs)
- **Brace Style**: K&R style (Attach)
- **Column Limit**: None (0)
- **Pointer Alignment**: Right (`int *ptr`)
- **Space Before Parens**: Control statements only
- **Keep Empty Lines**: At start of blocks and EOF

### Naming Conventions
- **Functions**: snake_case (e.g., `start_server`)
- **Variables**: snake_case
- **Constants/Macros**: UPPER_CASE (e.g., `STATUS_SUCCESS`, `PORT`, `BACKLOG`)
- **Structs**: snake_case with `_t` suffix for typedefs

### Error Handling Pattern
- Functions return `STATUS_SUCCESS` (0) or `STATUS_ERROR` (-1)
- Use `perror()` for system call error reporting
- Always close file descriptors on error paths

## Current Implementation

The main.c file contains a basic TCP server that:
1. Creates a socket using `socket(AF_INET, SOCK_STREAM, 0)`
2. Binds to port 9191 on all interfaces
3. Listens with backlog of 5 connections
4. Accepts one client connection
5. Returns the server file descriptor

**Note**: The current implementation has a bug - it returns the server fd instead of the client fd from accept().

## Development Patterns

### Socket Programming Pattern
```c
// Standard includes for socket programming
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Error handling pattern
if (operation_fails()) {
    perror("operation_name");
    close(fd);
    return STATUS_ERROR;
}
```

### Build Pattern
- Separate compilation: source files → object files → executable
- Include path: `-Iinclude` for header files
- Object files stored in `obj/` directory
- Executable stored in `bin/` directory

## Testing Approach

Currently no formal testing framework. Manual testing approach:
1. Build with `make`
2. Run server: `./bin/a.out`
3. Test with netcat: `nc localhost 9191`
4. Check for proper error handling and resource cleanup

## Important Gotchas

1. **File Descriptor Management**: Always close sockets on error paths
2. **Port Number**: Currently hardcoded to 9191, may need privileges for ports < 1024
3. **Blocking Operations**: accept() blocks indefinitely - no timeout handling
4. **Single Client**: Only handles one client connection then exits
5. **Resource Cleanup**: Need to close both server and client file descriptors

## Future Development Considerations

- Add client implementation
- Implement proper server loop for multiple clients
- Add timeout handling
- Implement proper signal handling for graceful shutdown
- Consider adding unit tests
- Add logging framework
- Implement configuration file support