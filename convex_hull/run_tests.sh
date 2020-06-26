make
for f in $(ls ./tests/inputs); do
    out=`./main_chan < ./tests/inputs/$f`
    actual=`cat ./tests/outputs/$f`
    out=`diff <(echo $out) <(echo $actual)`
    empty_line=`printf "\n"`
    if [[ "$out" = "$empty_line" ]]; then
        echo "$f: OK"
    else
        printf "$f\n$out\n"
    fi
done