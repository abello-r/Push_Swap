BLUE='\033[0;34m'
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
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
		printf "${BLUE}|-----${YELLOW}5 Números${BLUE}-----|${GREEN} [ $NUM1 $NUM2 $NUM3 $NUM4 $NUM5 ]${NC}\n\n"
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

function finish()
{
	clear
	printf "${BLUE}| Test Finalizado | ${NC}\n\nCualquier error escribir a ${RED}abello-r\n\n"
	exit
}
trap finish SIGINT

bash 5_test.sh