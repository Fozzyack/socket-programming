# Socket Programming Practice

A C project for learning and practicing socket programming concepts.

## Project Overview

This is a basic C project setup designed for socket programming exercises. The project includes a clean build system, code formatting configuration, and basic structure for network programming development.

## Quick Start

```bash
# Build the project
make

# Run the program
./bin/a.out

# Clean build artifacts
make clean
```

## Project Structure

```
├── include/          # Header files
│   └── common.h      # Common definitions and error codes
├── src/              # Source files
│   └── main.c        # Entry point
├── bin/              # Compiled executables (created by build)
├── obj/              # Object files (created by build)
├── Makefile          # Build configuration
├── .clang-format     # Code formatting rules
└── .gitignore        # Git ignore rules
```

## Building

The project uses a traditional Makefile with separate compilation:

- `make` - Build the main executable (`bin/a.out`)
- `make clean` - Remove all build artifacts
- `gcc -o bin/program obj/*.o -Iinclude` - Manual linking
- `gcc -c src/file.c -o obj/file.o -Iinclude` - Manual compilation

## Code Style

The project follows LLVM style with these key settings:
- 4-space indentation (no tabs)
- K&R brace style
- No column limit
- snake_case for variables/functions
- UPPER_CASE for macros

Use `clang-format` to format your code consistently.

## Error Handling

The project defines standard error codes in `include/common.h`:
- `STATUS_SUCCESS` (0) - Operation successful
- `STATUS_ERROR` (-1) - General error

Functions should return these values for consistent error handling.

## Getting Started

1. Add your socket programming code to `src/`
2. Create header files in `include/` as needed
3. Build with `make`
4. Test your implementation

## Development Tips

- Keep source files in `src/` and headers in `include/`
- Use the provided error codes for consistency
- Follow the existing code style and formatting
- Test individual components before integration
- Use `make clean` if you encounter build issues

## Future Enhancements

This project structure is ready for:
- Client/server socket implementations
- Network protocol development
- Multi-threaded network applications
- Error handling improvements
- Unit testing framework integration