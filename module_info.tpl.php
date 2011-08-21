<h2>Module Info</h2>
<div>
  <?php
    foreach($module_info as $key=>$value){
      $items[] = t('%label: @value', array('%label' => $key, '@value' => $value));
    }
    echo theme('item_list', $items);
  ?>
</div>


<?php
  //print_r($module_info);
?>
</pre>