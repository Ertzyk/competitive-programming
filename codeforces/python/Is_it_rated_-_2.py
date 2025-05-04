while True:
    try:
        response = input()
    except EOFError:
        break
    print("NO", flush=True)