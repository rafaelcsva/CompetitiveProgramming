<?php
	fscanf(STDIN, '%d\n', $n);

	$even = 0;
	$odd = 0;

	$a = explode(' ', trim(fgets(STDIN)));

	foreach ($a as &$num) {
		$num = intval($num);
		if ($num % 2 == 0) {
	    		$even++;
	  	} else {
			$odd++;
	  	}
	}

	if ($odd == 0) {
		echo "0";
	} else {
		$best = 0;
		
		for($i = 0 ; $i <= $even ; $i++){
			$best = max(min($i, $odd) + max(floor(($odd - $i) / 3), 0), $best);
		}
		
		echo $best;
	}

?>
