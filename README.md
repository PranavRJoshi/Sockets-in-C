This is just a basic C program that is used to create a Socket (tcp and http)

## To use TCP socket:
1. Navigate to `TCP Socket` directory:
```
cd TCP\ Socket
```
2. Build the executables:
```
make
```
3. Spilt the terminal and in the first window, use the command:
```
./tcp_server
```
4. On the second terminal, use the command:
```
./tcp_client
```
5. To remove all the executables and the `.dSYM` directory:
```
make clean
```

## To use HTTP socket:
1. Navigate to `HTTP Socket` directory:
```
cd HTTP\ Socket
```
2. Build the executables:
```
make
```
3. Split the terminal and in the first window, use the command:
```
./http_server
```
4. On the second terminal, use the command:
```
./http_client 127.0.0.1
```
5. To remove all the executables and the `.dSYM` directory:
```
make clean
```
