#include <list.h>
#include <proc/sched.h>
#include <mem/malloc.h>
#include <proc/proc.h>
#include <proc/switch.h>
#include <interrupt.h>

extern struct list plist;
extern struct list rlist;
extern struct process procs[PROC_NUM_MAX];

bool more_prio(const struct list_elem *a, const struct list_elem *b,void *aux);
struct process* get_next_proc(struct list *rlist_target);
int scheduling;									// interrupt.c

// Browse the 'active' array
struct process* sched_find_set(void) {
	struct process * result = NULL;
	
	
	// Your code goes here...
	
	return result;
}

struct process* get_next_proc(struct list *rlist_target) {
	struct list_elem *e;

	for(e = list_begin (rlist_target); e != list_end (rlist_target);
		e = list_next (e))
	{
		struct process* p = list_entry(e, struct process, elem_stat);

		if(p->state == PROC_RUN)
			return p;
	}
	return NULL;
}

void schedule(void)
{
	struct process *cur;
	struct process *next;

	/* You should modify this function.... */

	proc_wake();

	next = get_next_proc(&rlist);
	cur = cur_process;
	cur_process = next;
	cur_process -> time_slice = 0;

	switch_process(cur, next);
}
