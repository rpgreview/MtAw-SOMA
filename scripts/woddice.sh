#! /bin/bash

again_thres=10
while getopts a: opt; do
    case $opt in
        a)
            again_thres=$OPTARG
            ;;
    esac
done
shift $(( OPTIND - 1 ))
if [[ "$#" -lt 1 ]]; then
    2>&1 echo You need to specify how many dice to roll.
    exit 1
fi

get_rolls() {
    dice <<< "${1}xd10"
}

again_amount=$1
successes=0
while [[ $again_amount -gt 0 ]]; do
    base_results=($(get_rolls $again_amount))
    again_amount=0
    for d in "${base_results[@]}"; do
        if [[ $d -gt 7 ]]; then
            (( ++successes ))
            if [[ $d -ge $again_thres ]]; then
                (( ++again_amount ))
            fi
        fi
    done
done

printf "%d\n" "$successes"
