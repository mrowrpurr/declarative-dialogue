/*
    Declarative Dialogue


*/


/*
    Usage: use this to setup any procedures which are
           called directly from dialogue .ini files
           (only necessary for functions called nowhere else)

    procedure setup_dialogue_procedures begin
        dialogue_procs begin
            dialogue_proc do_something;
            dialogue_proc do_something_else;
        end
    end

    procedure start begin
        call setup_dialogue_procedures;
    end
*/
variable __dialogue_procedures_setup_once__;
variable __dialogue_procedure_name_to_invoke__;
variable __dialogue_procedure_invocation_result__;
#define dialogue_proc call
#define dialogue_procs \
    if __dialogue_procedures_setup_once__ then return; \
    __dialogue_procedures_setup_once__ = true; \
    if game_time < 0 then
#define call_dialogue_proc(proc_name_as_string) \
    __dialogue_procedure_name_to_invoke__ = proc_name_as_string; \
    __dialogue_procedure_invocation_result__ = __dialogue_procedure_name_to_invoke__(); \
    debug_msg("dialogue proc " + __dialogue_procedure_name_to_invoke__ + "() result: " + __dialogue_procedure_invocation_result__) // You *must* use the result or the optimizer won't invoke the procedure at all!
