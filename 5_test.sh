BLUE='\033[0;34m'
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

NUM1=$(($RANDOM%501))
NUM2=$(($RANDOM%401))
NUM3=$(($RANDOM%301))
NUM4=$(($RANDOM%201))
NUM5=$(($RANDOM%101))
COUNT=0

sleep 0.2 | printf "${BLUE}42 ${GREEN}Push_Swap ${RED}Tester ${BLUE}.${GREEN}.${RED}.${NC}"
clear

if [ -f push_swap ];
	then
		printf "${BLUE}|-----5 Números-----|${GREEN} [ $NUM1 $NUM2 $NUM3 $NUM4 $NUM5 ]${NC}\n\n"
		./push_swap "$NUM1 $NUM2 $NUM3 $NUM4 $NUM5"
		COUNT=$(./push_swap "$NUM1 $NUM2 $NUM3 $NUM4 $NUM5" | wc -l)
		if [ ${COUNT} -eq 0 ]
			then
				printf "${GREEN}Están ordenados${NC}\n"
		fi
		printf "\n${BLUE}|-------------------|${GREEN}${COUNT} Reglas | MAX 12${NC}\n\n"
	else
		make
		bash 5_test.sh
fi

if [ ${COUNT} -gt 12 ]
	then
		printf "${RED}Error${COUNT}\n${NC}"
		exit
fi

bash 5_test.sh
