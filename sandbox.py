def execute_python_code()
            break
        code_lines.append(line)
    
    code = "\n".join(code_lines)
    
    try:
        local_vars = {}
        exec(code, {}, local_vars)
    except Exception as e:
        print(f"Ошибка выполнения:\n{type(e).__name__}: {e}")

if __name__ == "__main__":
    execute_python_code()
