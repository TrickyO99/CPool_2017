#!/bin/bash
sed -e 's/theo1/Wile E. Coyote/g' -e 's/steven1/Daffy Duck/g' -e 's/arnaud1/Porky Pig/g' -e 's/pierre-jean/Marvin the Martian/g'| grep -e "Wile E. Coyote" -e "Daffy Duck" -e "Porky Pig" -e "Marvin the Martian"

