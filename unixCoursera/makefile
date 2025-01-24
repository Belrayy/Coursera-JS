# Define the target and dependencies
README.md: guessinggame.sh makefile
    @echo "# Guessing Game Project" > README.md
    @echo "" >> README.md
    @echo "Date and time: $$(date)" >> README.md
    @echo "" >> README.md
    @echo "Number of lines in guessinggame.sh: $$(wc -l < guessinggame.sh)" >> README.md

clean:
    rm -f README.md