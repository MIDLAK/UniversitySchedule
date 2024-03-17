#include "../headers/schedule.h"

int rooms_conflict(struct schedule_chromosome *schedule)
{
    /* аудитории циклов занятий */
    for (int i = 0; i < schedule->cycles_num; i++) { 
        int main_rnum = schedule->gens[i].room->room_num;
        int main_rbuild = schedule->gens[i].room->building_num;

        /* другие циклы занятий */
        for (int j = 0; j < schedule->cycles_num; j++) {
            if (i != j) { /* не сравнивать цикл занятий с самим собой */
                int rnum = schedule->gens[j].room->room_num;
                int rbuild = schedule->gens[j].room->building_num;

                /* проверка времени, если аудитории совпали */
                if (main_rnum == rnum && main_rbuild == rbuild) {
                    for(int t = 0; t < schedule->gens[i].pair_times_len; t++) {
                        for (int m; m < schedule->gens[j].pair_times_len; m++) {
                            int main_day = schedule->gens[i].pair_times[t].day, 
                                main_week = schedule->gens[i].pair_times[t].week,
                                main_pair = schedule->gens[i].pair_times[t].pair;

                            int day = schedule->gens[j].pair_times[m].day,
                                week = schedule->gens[j].pair_times[m].week,
                                pair = schedule->gens[j].pair_times[m].pair;

                            if (main_day == day && main_week == week && main_pair == pair)
                                return 1; /* считать все конфликты нет смысла */
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}

